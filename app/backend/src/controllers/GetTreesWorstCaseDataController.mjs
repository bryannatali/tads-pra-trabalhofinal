import { readFileSync } from 'fs';
import path, { dirname } from 'path';
import { fileURLToPath } from 'url';
import { Readable } from 'stream';
import { createInterface } from 'readline';

const __dirname = dirname(fileURLToPath(import.meta.url));

const GetTreesWorstCaseDataController = {
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

    const filesPath = path.join(__dirname, '..', '..', '..', '..');

    const arvoreAvlDataPiorCasoPath = filesPath + '/arvore_avl_data_pior_caso.csv';
    const arvoreRubroNegraDataPiorCasoPath = filesPath + '/arvore_rubro_negra_data_pior_caso.csv';
    const arvoreBDataPiorCasoPath = filesPath + '/arvore_b_data_pior_caso.csv';

    const arvoreAvlDataPiorCasoFile = readFileSync(arvoreAvlDataPiorCasoPath);
    const arvoreRubroNegraDataPiorCasoFile = readFileSync(arvoreRubroNegraDataPiorCasoPath);
    const arvoreBDataPiorCasoFile = readFileSync(arvoreBDataPiorCasoPath);

    const readableFile = new Readable();
    readableFile.push(arvoreAvlDataPiorCasoFile);
    readableFile.push(arvoreRubroNegraDataPiorCasoFile);
    readableFile.push(arvoreBDataPiorCasoFile);
    readableFile.push(null);

    const lines = createInterface({ input: readableFile });

    let count = 1;

    for await (const line of lines) {
      if (count > 2003) {
        const cols = line.split(';');


        const numConjunto = Number(cols[0]);
        const numOperacoes = Number(cols[1]);

        response.arvoreB.categories.push(numConjunto);
        response.arvoreB.data.push(numOperacoes);
      } else if (count > 1002 && count < 2003) {
        const cols = line.split(';');

        const numConjunto = Number(cols[0]);
        const numOperacoes = Number(cols[1]);

        response.arvoreRubroNegra.categories.push(numConjunto);
        response.arvoreRubroNegra.data.push(numOperacoes);
      } else if (count > 1 && count < 1002) {
        const cols = line.split(';');

        const numConjunto = Number(cols[0]);
        const numOperacoes = Number(cols[1]);

        response.arvoreAVL.categories.push(numConjunto);
        response.arvoreAVL.data.push(numOperacoes);
      }

      count++;
    }

    return res.json(response);
  }
}

export default GetTreesWorstCaseDataController;