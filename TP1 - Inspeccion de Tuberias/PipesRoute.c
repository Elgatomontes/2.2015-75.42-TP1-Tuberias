//
//  PipesRoute.c
//  TP1 - Inspeccion de Tuberias
//
//  Created by Gastón Montes on 9/9/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <stdlib.h>

#include "PipesRoute.h"

void pipesRouteCreate(PipesRoute *route, File *pipesFile, File *routeFiles) {
	route = (PipesRoute *)malloc(sizeof(PipesRoute));
	route->headNode = NULL;
}

void pipesRouteDestroy(PipesRoute *route) {
	struct RouteNode *currentNode = route->headNode;
	struct RouteNode *nextNode;

	while (currentNode != NULL) {
		nextNode = routeNodeNext(currentNode);

		routeNodeDestroy(currentNode);

		currentNode = nextNode;
	}

	free(route);
}

void pipesRouteAddNode(PipesRoute *route, struct RouteNode *node) {
	struct RouteNode *currentNode = route->headNode;

	if (currentNode == NULL) {
		route->headNode = node;
	} else {
		struct RouteNode *prevNode = NULL;

		while (currentNode != NULL) {
			prevNode = currentNode;
			currentNode = routeNodeNext(currentNode);
		}
		routeNodeSetNext(prevNode,node);
	}
}
