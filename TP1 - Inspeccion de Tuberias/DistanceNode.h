//
//  DistanceNode.h
//  TP1 - Inspeccion de Tuberias
//
//  Created by Gastón Montes on 20/9/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#ifndef DISTANCENODE_H_
#define DISTANCENODE_H_

struct DistanceNode {
	char firstNodeName;
	char secondNodeName;
	int distance;
	struct DistanceNode *next;
};

struct DistanceNode *distanceNodeCreate(char first, char second, int distance);

void distanceNodeDestroy(struct DistanceNode *node);

void distanceNodeSetNext(struct DistanceNode *node, struct DistanceNode *next);
struct DistanceNode *distanceNodeNext(struct DistanceNode *node);

#endif /* DISTANCENODE_H_ */
