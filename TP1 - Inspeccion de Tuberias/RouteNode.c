//
//  RouteNode.c
//  TP1 - Inspeccion de Tuberias
//
//  Created by Gastón Montes on 9/9/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <stdlib.h>

#include "RouteNode.h"

void routeNodeCreate(RouteNode *node, char nodeName) {
	node = (struct RouteNode *)malloc(sizeof(struct RouteNode));
	node->nodeName = nodeName;
	node->next = NULL;
	node->distanceToNextNode = -1;
}

void routeNodeDestroy(RouteNode *node) {
	node->nodeName = NULL;
	node->next = NULL;
	node->distanceToNextNode = -1;
	free(node);
}
