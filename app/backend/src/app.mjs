import express from 'express';
import cors from 'cors';

import { routes } from './routes.mjs';

const app = express();

app.use(cors({
  origin: ['http://localhost:3000'],
}));
app.use(express.json());
app.use(routes);

export { app }