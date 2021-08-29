import { BrowserRouter as Router, Switch, Route } from 'react-router-dom';

import Home from './pages/Home';
import MediumCase from './pages/MediumCase';
import WorstCase from './pages/WorstCase';

export default function Routes() {
  return (
    <Router>
      <Switch>
        <Route path="/" exact component={Home} />
        <Route path="/worst-cases" component={WorstCase} />
        <Route path="/medium-cases" exact component={MediumCase} />
      </Switch>
    </Router>
  )
}