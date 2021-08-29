import { Link } from "react-router-dom";

import './styles.css';

export default function Home() {
  return (
    <div className="home-container">
      <h1>Trabalho Final de PRA</h1>

      <Link to="/worst-cases">Casos Piores</Link>
      <Link to="/medium-cases">Casos Médios</Link>
    </div>
  );
}