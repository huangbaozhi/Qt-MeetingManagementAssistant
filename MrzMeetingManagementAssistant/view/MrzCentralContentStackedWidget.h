#ifndef MRZCENTRALCONTENTSTACKEDWIDGET_H
#define MRZCENTRALCONTENTSTACKEDWIDGET_H

#include <QWidget>

class MrzCentralContentStackedWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MrzCentralContentStackedWidget(QWidget *parent = nullptr);

signals:

private:
    void initUI();
};

#endif // MRZCENTRALCONTENTSTACKEDWIDGET_H
