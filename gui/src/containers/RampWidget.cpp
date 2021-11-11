#include <gui/containers/RampWidget.hpp>

RampWidget::RampWidget()
{

}

void RampWidget::initialize()
{
    RampWidgetBase::initialize();
}

void RampWidget::config(Point start_p, Point end_p, int32_t line_w, int32_t height) {
	setHeight(height);
	line1.setHeight(height);
	line1.setStart(start_p.x, start_p.y);
	line1.setEnd(end_p.x, end_p.y);
	line1.setLineWidth(line_w);
}
