//
//  PipesProcessor.h
//  TP1 - Inspeccion de Tuberias
//
//  Created by Gastón Montes on 9/9/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#ifndef PIPESPROCESSOR_H_
#define PIPESPROCESSOR_H_

#include "Arguments.h"
#include "File.h"

typedef struct {
	Arguments *arguments;
	File *measuresFile;
	File *pipesFile;
	File *routeFile;
} PipesProcessor;

void pipesProcessorCreate(PipesProcessor *processor,
						File *measures,
						File *pipes,
						File *route);

void pipesProcessorDestroy(PipesProcessor *processor);

#endif /* PIPESPROCESSOR_H_ */
