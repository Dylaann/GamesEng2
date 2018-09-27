#include "stdafx.h"
#include <iostream>
#include "GraphicProxy.h"

GraphicProxy::GraphicProxy()
{
	this->graphic = 0;
}

GraphicProxy::~GraphicProxy()
{
	if (graphic)
		delete graphic;
}

void GraphicProxy::Draw()
{
	getInstance()->Draw();
}

Graphic* GraphicProxy::getInstance(void) {

	if (!graphic)
		graphic = new Graphic();

	return graphic;
}