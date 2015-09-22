//
//  PipesRoute.h
//  TP1 - Inspeccion de Tuberias
//
//  Created by Gastón Montes on 9/9/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#ifndef PIPESROUTE_H_
#define PIPESROUTE_H_

#include "RouteNode.h"

typedef struct {
	struct RouteNode *headNode;
} PipesRoute;

void pipesRouteCreate(PipesRoute *route);

void pipesRouteDestroy(PipesRoute *route);

#endif /* PIPESROUTE_H_ */
