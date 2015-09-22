//
//  DistanceNode.c
//  TP1 - Inspeccion de Tuberias
//
//  Created by Gastón Montes on 20/9/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <stdlib.h>

#include "DistanceNode.h"

struct DistanceNode *distanceNodeCreate(char first, char second, int distance) {
	struct DistanceNode *newNode;
	newNode = (struct DistanceNode *)malloc(sizeof(struct DistanceNode));
	newNode->firstNodeName = first;
	newNode->secondNodeName = second;
	newNode->distance = distance;

	return newNode;
}

void distanceNodeDestroy(struct DistanceNode *node) {
	free(node);
}

void distanceNodeSetNext(struct DistanceNode *node, struct DistanceNode *next) {
	node->next = next;
}

struct DistanceNode *distanceNodeNext(struct DistanceNode *node) {
	return node->next;
}
