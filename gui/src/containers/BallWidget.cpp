#include <gui/containers/BallWidget.hpp>

#define _USE_MATH_DEFINES
#include <math.h>

#include <gui/utils/Geometry.hpp>

void BallWidget::initialize() {
    BallWidgetBase::initialize();
	setVisible(false);
	setTouchable(false);
}
