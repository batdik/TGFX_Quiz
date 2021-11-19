#ifndef BALLWIDGET_HPP
#define BALLWIDGET_HPP

#include <gui_generated/containers/BallWidgetBase.hpp>

class BallWidget : public BallWidgetBase
{
public:
	void initialize() final;
	void rotate(float step);
};

#endif // BALLWIDGET_HPP
