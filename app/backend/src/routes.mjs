import { Router } from 'express';

import GetTreesWorstCaseDataController from './controllers/GetTreesWorstCaseDataController.mjs';
import GetTreesMediumCaseDataController from './controllers/GetTreesMediumCaseDataController.mjs';

const routes = Router();

routes.get('/worst-cases', GetTreesWorstCaseDataController.index);
routes.get('/medium-cases', GetTreesMediumCaseDataController.index);

export { routes };