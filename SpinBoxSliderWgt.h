#ifndef SPINBOXSLIDERWGT_H
#define SPINBOXSLIDERWGT_H

#include <QWidget>
#include <QSpinBox>
#include <QSlider>
#include <QVBoxLayout>

class SpinBoxSliderWgt : public QWidget
{
	Q_OBJECT
public:
	SpinBoxSliderWgt( int minValue, int maxValue, int step, QWidget *parent = nullptr );

	void setValue( int value );
	int getValue();

signals:
	void spinBoxValueChanged( int value );
	void sliderValueChanged( int value );

private slots:
	void onSpinBoxValueChanged( int value );
	void onSliderValueChanged( int value );

private:
	void createWidgets( int minValue, int maxValue, int step );
	void placeWidgets();
	void connectSignals();

private:
	QSpinBox *spinBox;
	QSlider *slider;
	int value;
};

#endif // SPINBOXSLIDERWGT_H
