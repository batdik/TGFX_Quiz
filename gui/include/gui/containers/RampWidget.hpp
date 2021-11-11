#ifndef RAMPWIDGET_HPP
#define RAMPWIDGET_HPP

#include <gui_generated/containers/RampWidgetBase.hpp>

class RampWidget : public RampWidgetBase
{
public:
    RampWidget();

    void initialize() final;

	void config(Point start_p, Point end_p, int32_t line_w, int32_t height) final;

protected:
};

#endif // RAMPWIDGET_HPP
