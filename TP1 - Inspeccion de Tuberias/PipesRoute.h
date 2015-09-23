//
//  PipesRoute.h
//  TP1 - Inspeccion de Tuberias
//
//  Created by Gastón Montes on 9/9/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#ifndef PIPESROUTE_H_
#define PIPESROUTE_H_

#include "PipesDistances.h"
#include "RouteNode.h"
#include "File.h"

typedef struct {
	struct RouteNode *headNode;
	PipesDistances *distances;
} PipesRoute;

void pipesRouteCreate(PipesRoute **route, File *routeFiles, File *pipesFile);

void pipesRouteDestroy(PipesRoute *route);

int pipesRouteLenght(PipesRoute *route);

#endif /* PIPESROUTE_H_ */
