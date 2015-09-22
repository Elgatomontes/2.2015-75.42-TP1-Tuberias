//
//  PipesProcessor.c
//  TP1 - Inspeccion de Tuberias
//
//  Created by Gastón Montes on 9/9/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include "PipesProcessor.h"

void createArguments(PipesProcessor *processor, File *measures) {
	Arguments newArguments;
	argumentsCreate(&newArguments, processor->measures);
	processor->arguments = &newArguments;
}

void pipesProcessorCreate(PipesProcessor *processor,
		File *measuresFile,
		File *pipesFile,
		File *routeFile) {
	processor->measures = measuresFile;
	processor->pipes = pipesFile;
	processor->routeFile = routeFile;

	createArguments(processor, processor->measures);

	pipesRouteCreate(&(processor->route), processor->routeFile);
	pipesDistancesCreate(&(processor->distances), processor->pipes);
}

void pipesProcessorDestroy(PipesProcessor *processor) {
	argumentsDestroy(processor->arguments);
	pipesRouteDestroy(processor->route);
	pipesDistancesDestroy(processor->distances);
}

void pipesProcessorProcess(PipesProcessor *processor) {
	// Read file.
}
