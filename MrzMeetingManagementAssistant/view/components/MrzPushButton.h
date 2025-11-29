#ifndef MRZPUSHBUTTON_H
#define MRZPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QEnterEvent>
#include <QMouseEvent>

class MrzPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MrzPushButton(QWidget *parent = nullptr);

    // 当前状态
    enum ButtonState {
        StateNormal,
        StateHover,
        StatePressed
    };
    ButtonState m_currentState;

signals:

public:
    void setButtonText(const QString &text);

    // 设置三态颜色
    void setNormalColor(const QColor &color);
    void setHoverColor(const QColor &color);
    void setPressedColor(const QColor &color);

    // 设置三态图标
    void setNormalIcon(const QString &iconPath);
    void setHoverIcon(const QString &iconPath);
    void setPressedIcon(const QString &iconPath);

protected:
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    void initButtonStyle();
    void updateButtonStyle();
    void updateIcon();

private:
    QWidget *m_pMainWgt;
    QLabel *m_pLogoLbl;
    QLabel *m_pTextLbl;

    // 三态颜色
    QColor m_normalColor;
    QColor m_hoverColor;
    QColor m_pressedColor;

    // 三态图标
    QString m_normalIcon;
    QString m_hoverIcon;
    QString m_pressedIcon;
};

#endif // MRZPUSHBUTTON_H
