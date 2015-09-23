//
//  RouteNode.c
//  TP1 - Inspeccion de Tuberias
//
//  Created by Gastón Montes on 9/9/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>

#include "RouteNode.h"

struct RouteNode * routeNodeCreate(char *nodeName) {
	struct RouteNode *newNode;
	newNode = (struct RouteNode *)malloc(sizeof(struct RouteNode));
	newNode->next      = NULL;
	newNode->distanceToRoot = -1;

	newNode->nodeName  = (char *)malloc(sizeof(nodeName));
	snprintf(newNode->nodeName, sizeof(nodeName), "%s",nodeName);

	return newNode;
}

void routeNodeDestroy(struct RouteNode *node) {
	free(node->nodeName);
	free(node);
}

struct RouteNode *routeNodeNext(struct RouteNode *node) {
	return node->next;
}

void routeNodeSetNext(struct RouteNode *node, struct RouteNode *next) {
	node->next = next;
}

int routeNodeDistanceToRoot(struct RouteNode *node) {
	return node->distanceToRoot;
}

void routeNodeSetDistanceToRoot(struct RouteNode *node, int distance) {
	node->distanceToRoot = distance;
}

char *routeNodeName(struct RouteNode *node) {
	return node->nodeName;
}
