//
//  RouteNode.h
//  TP1 - Inspeccion de Tuberias
//
//  Created by Gastón Montes on 9/9/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#ifndef ROUTENODE_H_
#define ROUTENODE_H_

typedef struct {
	char nodeName;
	struct RouteNode *next;
	int distanceToNextNode;
} RouteNode;

#endif /* ROUTENODE_H_ */
