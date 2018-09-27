#ifndef GRAPHICPROXY_H
#define GRAPHICPROXY_H

#include "IGraphic.h"
#include "Graphic.h"

using namespace std;

class GraphicProxy : public IGraphic
{
public:
	GraphicProxy();
	~GraphicProxy();
	void Draw();
private:
	Graphic* graphic;
	Graphic* getInstance(void);
};

#endif // !GRAPHIC_PROXY_H

