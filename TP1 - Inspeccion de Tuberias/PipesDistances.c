//
//  PipesDistances.c
//  TP1 - Inspeccion de Tuberias
//
//  Created by Gastón Montes on 20/9/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>

#include "PipesDistances.h"

static int const kLineMaxLenght = 52; // Name1(20) * 2 + Distance(4) + Comma(4).

void addNewNode(PipesDistances *distances, struct DistanceNode *node) {
	struct DistanceNode *currentNode = distances->headNode;

	if (currentNode == NULL) {
		printf("Adding head node: %c -> %c distance: %i\n",
				node->firstNodeName,
				node->secondNodeName,
				node->distance);
		distances->headNode = node;
	} else {
		struct DistanceNode *prevNode = NULL;

		while (currentNode != NULL) {
			prevNode = currentNode;
			currentNode = distanceNodeNext(currentNode);
		}

		distanceNodeSetNext(prevNode, node);

		printf("Adding node: %c -> %c distance: %i\n",
				node->firstNodeName,
				node->secondNodeName,
				node->distance);
	}
}

void createDistancesList(PipesDistances *distances, File *pipesFile) {
	char *lineBuffer = (char *)malloc(sizeof(char) * kLineMaxLenght);

	fileReadLine(pipesFile, lineBuffer, kLineMaxLenght);

	while (fileEndOfFile(pipesFile) != EOF) {
		char *firstName = "";
		char *secondName = "";
		int distance;
		sscanf(lineBuffer, "%s,%i,%s", firstName, &distance, secondName);

		struct DistanceNode *newNode;
		newNode = distanceNodeCreate(firstName[0], secondName[0], distance);
		addNewNode(distances, newNode);
		fileReadLine(pipesFile, lineBuffer, kLineMaxLenght);
	}

	free(lineBuffer);
}

void pipesDistancesCreate(PipesDistances **distances, File *pipesFile) {
	PipesDistances *newDistances;
	newDistances = (PipesDistances *)malloc(sizeof(PipesDistances));
	newDistances->headNode = NULL;
	*distances = newDistances;

	createDistancesList(*distances, pipesFile);
}

void pipesDistancesDestroy(PipesDistances *route) {
	struct DistanceNode *currentNode = route->headNode;
	struct DistanceNode *nextNode = NULL;

	while (currentNode != NULL) {
		nextNode = distanceNodeNext(currentNode);

		distanceNodeDestroy(currentNode);

		currentNode = nextNode;
	}

	free(route);
}
