#include "SpinBoxSliderWgt.h"


SpinBoxSliderWgt::SpinBoxSliderWgt( int minValue, int maxValue, int step, QWidget *parent )
	: QWidget( parent )
{
	createWidgets( minValue, maxValue, step );
	placeWidgets();
	connectSignals();
}

void SpinBoxSliderWgt::setValue( int value )
{
	this->value = value;
	spinBox->setValue( value );
}

int SpinBoxSliderWgt::getValue()
{
	return this->value;
}

void SpinBoxSliderWgt::createWidgets( int minValue, int maxValue, int step )
{
	spinBox = new QSpinBox();
	slider = new QSlider( Qt::Horizontal );

	spinBox->setMinimum( minValue );
	spinBox->setMaximum( maxValue );
	spinBox->setSingleStep( step );

	slider->setMinimum( minValue );
	slider->setMaximum( maxValue );
	slider->setSingleStep( step );

	this->value = spinBox->value();
}

void SpinBoxSliderWgt::placeWidgets()
{
	auto *mainLay = new QVBoxLayout();
	mainLay->addWidget( spinBox );
	mainLay->addWidget( slider );
	setLayout(mainLay);
}

void SpinBoxSliderWgt::connectSignals()
{
	connect( spinBox, SIGNAL( valueChanged( int ) ), this, SLOT( onSpinBoxValueChanged( int ) ) );
	connect( slider, SIGNAL( valueChanged( int ) ), this, SLOT( onSliderValueChanged( int ) ) );
}

void SpinBoxSliderWgt::onSpinBoxValueChanged( int value )
{
	emit spinBoxValueChanged( value );
	slider->setValue( value );
}

void SpinBoxSliderWgt::onSliderValueChanged( int value )
{
	emit sliderValueChanged( value );
	spinBox->setValue( value );
}
