import { useEffect, useState } from "react";
import { FiArrowLeft } from "react-icons/fi";
import { Link } from "react-router-dom";
import Chart from 'react-apexcharts';

import api from "../../services/api";

import './styles.css';

export default function MediumCase() {
  const [mediumCaseSeries, setMediumCaseSeries] = useState([]);
  const [mediumCaseCategories, setMediumCaseCategories] = useState([]);

  const height = window.innerHeight - 250;

  useEffect(() => {
    async function loadChartData() {
      const { data } = await api.get('/medium-cases');

      setMediumCaseCategories(data.arvoreRubroNegra.categories);
      setMediumCaseSeries([
        // {
        //   name: 'Árvore AVL',
        //   data: data.arvoreAVL.data,
        // },
        {
          name: 'Árvore Rubro Negra',
          data: data.arvoreRubroNegra.data,
        },
        {
          name: 'Árvore B',
          data: data.arvoreB.data,
        }
      ]);
    }

    loadChartData();
  }, []);

  return (
    <div className="medium-case-container">
      <header>
        <Link to="/">
          <FiArrowLeft size={40} />
          Home /
        </Link>
        <h1>Casos Médios</h1>
      </header>

      <Chart
        height={height}
        series={mediumCaseSeries}
        options={{
          chart: {
            zoom: {
              enabled: false,
            },
            animations: {
              enabled: false,
            },
          },
          stroke: { curve: 'smooth' },
          xaxis: {
            tickAmount: 'dataPoints',
            categories: mediumCaseCategories,
          },
          yaxis: {
            tickAmount: 4,
            labels: {
              formatter: (value) => {
                const val = Math.abs(value);

                if (val >= 1000 && val < 1000000) {
                  return (val / 1000).toFixed(1) + " K";
                }

                if (val >= 1000000) {
                  return (val / 1000000).toFixed(1) + " M";
                }

                return val;
              }
            }
          },
          title: {
            text: "Número de Operações por Tamanho de Conjuntos em Árvores AVL, Rubro Negra e B",
          }
        }}
      />
    </div>
  );
}