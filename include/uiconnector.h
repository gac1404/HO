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
    Q_PROPERTY(QString someVar READ someVar WRITE setSomeVar NOTIFY someVarChanged)

public:
  void setSampleText(const QString sampleText);
  QString sampleText() const;
  void callMe();

  QString someVar();

  void Dupa();

signals:
  void sampleTextChanged(QString &sampleText);
  void someVarChanged();


public slots:
    void setSomeVar(QString str);

private:
  QString mText{"Text"};
  QString test;

  QString m_someVar = "dddd";
};
