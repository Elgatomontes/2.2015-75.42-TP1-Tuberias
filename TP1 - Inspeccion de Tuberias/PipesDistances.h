//
//  PipesDistances.h
//  TP1 - Inspeccion de Tuberias
//
//  Created by Gastón Montes on 20/9/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#ifndef PIPESDISTANCES_H_
#define PIPESDISTANCES_H_

#include "DistanceNode.h"
#include "File.h"

typedef struct {
	struct DistanceNode *headNode;
} PipesDistances;

void pipesDistancesCreate(PipesDistances **distances, File *pipesFile);

void pipesDistancesDestroy(PipesDistances *distances);

#endif /* PIPESDISTANCES_H_ */
