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

static int const kNameMaxLenght = 20;
static int const kLineMaxLenght = 52; // Name1(20)*2 + Distance(4) + Comma(1)*2.

void addNewNode(PipesDistances *distances, struct DistanceNode *node) {
	struct DistanceNode *currentNode = distances->headNode;

	if (currentNode == NULL) {
		printf("Adding head node: %s -> %s distance: %i\n",
				node->firstNodeName,
				node->secondNodeName,
				node->distance);
		distances->headNode = node;
		distanceNodeSetNext(node, NULL);
	} else {
		struct DistanceNode *prevNode = NULL;

		while (currentNode != NULL) {
			prevNode = currentNode;
			currentNode = distanceNodeNext(currentNode);
		}
		distanceNodeSetNext(prevNode, node);
		distanceNodeSetNext(node, NULL);

		printf("Adding node: %s -> %s distance: %i\n",
				node->firstNodeName,
				node->secondNodeName,
				node->distance);
	}
}

void createDistancesList(PipesDistances *distances, File *pipesFile) {
	char *lineBuffer = (char *)malloc(sizeof(char) * kLineMaxLenght);
	char *firstName = (char *)malloc(sizeof(char) * kNameMaxLenght);
	char *secondName = (char *)malloc(sizeof(char) * kNameMaxLenght);

	fileReadLine(pipesFile, lineBuffer, kLineMaxLenght);

	while (fileEndOfFile(pipesFile) != EOF) {
		int distance = 0;
		sscanf(lineBuffer, "%20[^,],%i,%s", firstName, &distance, secondName);

		struct DistanceNode *newNode;
		newNode = distanceNodeCreate(firstName, secondName, distance);
		addNewNode(distances, newNode);
		fileReadLine(pipesFile, lineBuffer, kLineMaxLenght);
	}

	free(lineBuffer);
	free(firstName);
	free(secondName);
}

void pipesDistancesCreate(PipesDistances **distances, File *pipesFile) {
	PipesDistances *newDistances;
	newDistances = (PipesDistances *)malloc(sizeof(PipesDistances));
	newDistances->headNode = NULL;
	*distances = newDistances;

	createDistancesList(*distances, pipesFile);
}

void pipesDistancesDestroy(PipesDistances *distances) {
	struct DistanceNode *currentNode = distances->headNode;
	struct DistanceNode *nextNode = NULL;

	while (currentNode != NULL) {
		nextNode = distanceNodeNext(currentNode);

		distanceNodeDestroy(currentNode);

		currentNode = nextNode;
	}

	free(distances);
}
