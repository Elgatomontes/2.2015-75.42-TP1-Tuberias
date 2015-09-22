//
//  PipesProcessor.c
//  TP1 - Inspeccion de Tuberias
//
//  Created by Gastón Montes on 9/9/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include "PipesProcessor.h"

void pipesProcessorCreate(PipesProcessor *processor,
						File *measures,
						File *pipes,
						File *route) {
	processor->measuresFile = measures;
	processor->pipesFile = pipes;
	processor->routeFile = route;

	argumentsCreate(processor->arguments, processor->measuresFile);
}

void pipesProcessorDestroy(PipesProcessor *processor) {
	argumentsDestroy(processor->arguments);
}
