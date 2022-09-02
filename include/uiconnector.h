#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlProperty>

#include <iostream>

#include <QDebug>

class UiConnector : public QObject {
  Q_OBJECT
  Q_PROPERTY(QString sampleText READ sampleText WRITE setSampleText NOTIFY
                 sampleTextChanged)

public:
  void setSampleText(const QString sampleText);
  QString sampleText() const;

signals:
  void sampleTextChanged(QString &sampleText);

private:
  QString mText{"Text"};
  QString test;
};
