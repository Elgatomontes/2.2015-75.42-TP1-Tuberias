//
//  PipesRoute.c
//  TP1 - Inspeccion de Tuberias
//
//  Created by Gastón Montes on 9/9/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <stdlib.h>

#include "PipesRoute.h"

static int const kNodeNameMaxLenght = 22; // name(20) + \n char(2).

void addNodeToRoute(PipesRoute *route, struct RouteNode *node) {
	struct RouteNode *currentNode = route->headNode;

	if (currentNode == NULL) {
		route->headNode = node;
		routeNodeSetDistanceToRoot(node, 0);
		routeNodeSetNext(node, NULL);
	} else {
		struct RouteNode *prevNode = NULL;

		while (currentNode != NULL) {
			prevNode = currentNode;
			currentNode = routeNodeNext(currentNode);
		}
		routeNodeSetNext(prevNode, node);
		routeNodeSetNext(node, NULL);

		int prevDistanceToRoot = routeNodeDistanceToRoot(prevNode);
		int distanceToPrev = 2; // @TODO: - Calculate distance to previous.
		routeNodeSetDistanceToRoot(node, prevDistanceToRoot + distanceToPrev);
	}
}

void createRouteList(PipesRoute *route, File *routeFiles) {
	char *nodeNameBuffer = (char *)malloc(sizeof(char) * kNodeNameMaxLenght);

	fileReadLine(routeFiles, nodeNameBuffer, kNodeNameMaxLenght);

	while (fileEndOfFile(routeFiles) != EOF) {
		struct RouteNode *newNode = routeNodeCreate(nodeNameBuffer);
		addNodeToRoute(route, newNode);
		fileReadLine(routeFiles, nodeNameBuffer, kNodeNameMaxLenght);
	}

	free(nodeNameBuffer);
}

void createDistanceList(PipesRoute *route, File *pipesFile) {
	pipesDistancesCreate(&route->distances, pipesFile);
}

void pipesRouteCreate(PipesRoute **route, File *routeFiles, File *pipesFile) {
	PipesRoute *newRoute = (PipesRoute *)malloc(sizeof(PipesRoute));
	newRoute->headNode = NULL;
	newRoute->distances = NULL;
	*route = newRoute;

	createRouteList(*route, routeFiles);
	createDistanceList(*route, pipesFile);
}

void pipesRouteDestroy(PipesRoute *route) {
	struct RouteNode *currentNode = route->headNode;
	struct RouteNode *nextNode = NULL;

	while (currentNode != NULL) {
		nextNode = routeNodeNext(currentNode);

		routeNodeDestroy(currentNode);

		currentNode = nextNode;
	}

	pipesDistancesDestroy(route->distances);
	free(route);
}
