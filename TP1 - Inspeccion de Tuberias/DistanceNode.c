//
//  DistanceNode.c
//  TP1 - Inspeccion de Tuberias
//
//  Created by Gastón Montes on 20/9/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "DistanceNode.h"

struct DistanceNode *distanceNodeCreate(char *first,
		char *second,
		int distance) {
	struct DistanceNode *newNode;
	newNode = (struct DistanceNode *)malloc(sizeof(struct DistanceNode));
	newNode->firstNodeName = (char *)malloc(sizeof(first));
	newNode->secondNodeName = (char *)malloc(sizeof(second));

	snprintf(newNode->firstNodeName, sizeof(first), "%s",first);
	snprintf(newNode->secondNodeName, sizeof(second), "%s",second);
	newNode->distance = distance;
	newNode->next = NULL;
	return newNode;
}

void distanceNodeDestroy(struct DistanceNode *node) {
	free(node->firstNodeName);
	free(node->secondNodeName);
	free(node);
}

void distanceNodeSetNext(struct DistanceNode *node, struct DistanceNode *next) {
	node->next = next;
}

struct DistanceNode *distanceNodeNext(struct DistanceNode *node) {
	return node->next;
}

char *distanceNodeFirstNodeName(struct DistanceNode *node) {
	return node->firstNodeName;
}

char *distanceNodeSecondNodeName(struct DistanceNode *node) {
	return node->secondNodeName;
}

int distanceNodeDistance(struct DistanceNode *node) {
	return node->distance;
}
