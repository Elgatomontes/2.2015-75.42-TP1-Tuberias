//
//  PipesRoute.c
//  TP1 - Inspeccion de Tuberias
//
//  Created by Gastón Montes on 9/9/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <stdlib.h>

#include "PipesRoute.h"

static int const kNodeNameMaxLenght = 454; // name + \n char.

void createList(PipesRoute *route, File *pipesFile, File *routeFiles) {
	char *nodeNameBuffer = (char *)malloc(sizeof(char) * kNodeNameMaxLenght);

	fileReadLine(routeFiles, nodeNameBuffer, kNodeNameMaxLenght);

	while (fileEndOfFile(routeFiles) != EOF) {
		printf("Nodo leído: %s", nodeNameBuffer);
		fileReadLine(routeFiles, nodeNameBuffer, kNodeNameMaxLenght);
	}

	free(nodeNameBuffer);
}

void pipesRouteCreate(PipesRoute **route, File *pipesFile, File *routeFiles) {
	PipesRoute *newRoute = (PipesRoute *)malloc(sizeof(PipesRoute));
	newRoute->headNode = NULL;
	*route = newRoute;

	createList(*route, pipesFile, routeFiles);
}

void pipesRouteDestroy(PipesRoute *route) {
	struct RouteNode *currentNode = route->headNode;
	struct RouteNode *nextNode = NULL;

	while (currentNode != NULL) {
		printf("Llegué hasta aca\n");
		nextNode = routeNodeNext(currentNode);
		printf("Llegué hasta aca 1\n");

		routeNodeDestroy(currentNode);
		printf("Llegué hasta aca 2\n");

		currentNode = nextNode;
		printf("Llegué hasta aca 3\n");
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
