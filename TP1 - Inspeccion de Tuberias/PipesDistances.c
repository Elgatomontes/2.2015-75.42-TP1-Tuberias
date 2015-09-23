//
//  PipesDistances.c
//  TP1 - Inspeccion de Tuberias
//
//  Created by Gastón Montes on 20/9/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "PipesDistances.h"

static int const kNameMaxLenght = 20;
static int const kLineMaxLenght = 52; // Name1(20)*2 + Distance(4) + Comma(1)*2.

void addNewNode(PipesDistances *distances, struct DistanceNode *node) {
	struct DistanceNode *currentNode = distances->headNode;

	if (currentNode == NULL) {
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
	}
}

void createDistancesList(PipesDistances *distances, File *pipesFile) {
	char *lineBuffer = (char *)malloc(sizeof(char) * kLineMaxLenght);

	fileReadLine(pipesFile, lineBuffer, kLineMaxLenght);

	while (fileEndOfFile(pipesFile) != EOF) {
		int distance = 0;
		char firstName[kNameMaxLenght];
		char secondName[kNameMaxLenght];

		sscanf(lineBuffer, "%20[^,],%d,%s", firstName, &distance, secondName);

		struct DistanceNode *newNode;
		newNode = distanceNodeCreate(firstName, secondName, distance);
		addNewNode(distances, newNode);
		fileReadLine(pipesFile, lineBuffer, kLineMaxLenght);
	}

	free(lineBuffer);
}

void printDistancesList(PipesDistances *distances) {
	printf("IMPRIMIENDO LA LISTA DE DISTANCIAS\n");
	struct DistanceNode *currentNode = distances->headNode;
	struct DistanceNode *prevNode = NULL;

	while (currentNode != NULL) {
		printf("Nodo: %s -> %s, Distancia: %i\n",
				distanceNodeFirstNodeName(currentNode),
				distanceNodeSecondNodeName(currentNode),
				distanceNodeDistance(currentNode));
		prevNode = currentNode;
		currentNode = distanceNodeNext(prevNode);
	}
}

void pipesDistancesCreate(PipesDistances **distances, File *pipesFile) {
	PipesDistances *newDistances;
	newDistances = (PipesDistances *)malloc(sizeof(PipesDistances));
	newDistances->headNode = NULL;
	*distances = newDistances;

	createDistancesList(*distances, pipesFile);
	printDistancesList(*distances);
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

int pipesDistancesBetween(PipesDistances *distances, char *first, char *second){
	struct DistanceNode *currentNode = distances->headNode;
	struct DistanceNode *nextNode = NULL;

	while (currentNode != NULL) {
		nextNode = distanceNodeNext(currentNode);

		char *currentNodeFirstName = distanceNodeFirstNodeName(currentNode);
		char *currentNodeSecondName = distanceNodeSecondNodeName(currentNode);

		if ((strcmp(first, currentNodeFirstName) == 0 &&
				strcmp(second, currentNodeSecondName) == 0) ||
				(strcmp(second, currentNodeFirstName) == 0 &&
						strcmp(first, currentNodeSecondName))) {
			return distanceNodeDistance(currentNode);
		}

		currentNode = nextNode;
	}

	return -1;
}
