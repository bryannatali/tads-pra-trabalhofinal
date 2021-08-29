import { readFileSync } from 'fs';
import path, { dirname } from 'path';
import { fileURLToPath } from 'url';
import { Readable } from 'stream';
import { createInterface } from 'readline';

const __dirname = dirname(fileURLToPath(import.meta.url));

const GetTreesMediumCaseDataController = {
  index: async (req, res) => {
    let response = {
      arvoreAVL: {
        categories: [],
        data: [],
      },
      arvoreRubroNegra: {
        categories: [],
        data: [],
      },
      arvoreB: {
        categories: [],
        data: [],
      },
    }

    const mediumCaseArvoreRubroNegraDictionary = {}
    const mediumCaseArvoreBDictionary = {}

    const filesPath = path.join(__dirname, '..', '..', '..', '..');

    const arvoreRubroNegraDataMedioCasoPath = filesPath + '/arvore_rubro_negra_data_medio_caso.csv';
    const arvoreBDataMedioCasoPath = filesPath + '/arvore_b_data_medio_caso.csv';

    const arvoreRubroNegraDataMedioCasoFile = readFileSync(arvoreRubroNegraDataMedioCasoPath);
    const arvoreBDataMedioCasoFile = readFileSync(arvoreBDataMedioCasoPath);

    const readableFile = new Readable();
    readableFile.push(arvoreRubroNegraDataMedioCasoFile);
    readableFile.push(arvoreBDataMedioCasoFile);
    readableFile.push(null);

    const lines = createInterface({ input: readableFile });

    let count = 1;

    for await (const line of lines) {
      if (count > 10002) {
        const cols = line.split(';');

        // const numTeste = Number(cols[0]);
        const numConjunto = cols[1];
        const numOperacoes = Number(cols[2]);

        if (!mediumCaseArvoreBDictionary[numConjunto]) {
          mediumCaseArvoreBDictionary[numConjunto] = numOperacoes;
        } else {
          mediumCaseArvoreBDictionary[numConjunto] += numOperacoes;
        }
      } else if (count > 1 && count < 10002) {
        const cols = line.split(';');

        // const numTeste = Number(cols[0]);
        const numConjunto = cols[1];
        const numOperacoes = Number(cols[2]);

        if (!mediumCaseArvoreRubroNegraDictionary[numConjunto]) {
          mediumCaseArvoreRubroNegraDictionary[numConjunto] = numOperacoes;
        } else {
          mediumCaseArvoreRubroNegraDictionary[numConjunto] += numOperacoes;
        }
      }

      count++;
    }

    Object.keys(mediumCaseArvoreRubroNegraDictionary).forEach(mediumCaseArvoreRubroNegraConjunto => {
      const numConjunto = Number(mediumCaseArvoreRubroNegraConjunto);
      const numOperacoes = Math.round(mediumCaseArvoreRubroNegraDictionary[mediumCaseArvoreRubroNegraConjunto] / 10);

      response.arvoreRubroNegra.categories.push(numConjunto);
      response.arvoreRubroNegra.data.push(numOperacoes);
    });

    Object.keys(mediumCaseArvoreBDictionary).forEach(mediumCaseArvoreBConjunto => {
      const numConjunto = Number(mediumCaseArvoreBConjunto);
      const numOperacoes = Math.round(mediumCaseArvoreBDictionary[mediumCaseArvoreBConjunto] / 10);

      response.arvoreB.categories.push(numConjunto);
      response.arvoreB.data.push(numOperacoes);
    });

    return res.json(response);
  }
}

export default GetTreesMediumCaseDataController;