import { useEffect, useState } from "react";
import { Link } from "react-router-dom";
import { FiArrowLeft } from 'react-icons/fi';
import Chart from 'react-apexcharts';

import api from "../../services/api";

import './styles.css';

export default function WorstCase() {
  const [worstCaseSeries, setWorstCaseSeries] = useState([]);
  const [worstCaseCategories, setWorstCaseCategories] = useState([]);

  const height = window.innerHeight - 250;

  useEffect(() => {
    async function loadChartData() {
      const { data } = await api.get('/worst-cases');

      setWorstCaseCategories(data.arvoreRubroNegra.categories);
      setWorstCaseSeries([
        {
          name: 'Árvore AVL',
          data: data.arvoreAVL.data,
        },
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
    <div className="worst-case-container">
      <header>
        <Link to="/">
          <FiArrowLeft size={40} />
          Home /
        </Link>
        <h1>Casos Piores</h1>
      </header>

      <Chart
        height={height}
        series={worstCaseSeries}
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
            categories: worstCaseCategories,
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