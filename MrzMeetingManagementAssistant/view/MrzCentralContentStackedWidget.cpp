#include "MrzCentralContentStackedWidget.h"

/**
 * @brief MrzCentralContentStackedWidget
 * @param parent
 * @details 栈窗口
 */

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

MrzCentralContentStackedWidget::MrzCentralContentStackedWidget(QWidget *parent)
    : QWidget{parent}
{
    initUI();
}

void MrzCentralContentStackedWidget::initUI()
{
    QHBoxLayout *pMainLyt = new QHBoxLayout(this);
    pMainLyt->setContentsMargins(0, 0, 0, 0);
    QWidget *pMainWgt = new QWidget(this);
    pMainWgt->setMinimumSize(1160, 840);
    pMainWgt->setStyleSheet("QWidget{border-radius: 0px 0px 0px 0px;background-color: rgba(255,255,255,1);border: 0px;}");

    pMainLyt->addWidget(pMainWgt);
}
