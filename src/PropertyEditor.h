#ifndef PROPERTYEDITOR_H
#define PROPERTYEDITOR_H

#include "PropertyDelegate.h"

#include <QMetaProperty>
#include <QStandardItemModel>
#include <QTreeView>

class PropertyEditor : public QTreeView {
Q_OBJECT
private:
	QObject *m_object;
	QStandardItemModel m_model;
	PropertyDelegate m_delegate;
public:
	class ValueItem: public QStandardItem {
	private:
		QObject *m_object;
		QMetaProperty m_metaProperty;
		QVariant m_value;
	public:
		ValueItem(const QVariant &value, QObject *object, const QMetaProperty &metaProperty);

		QObject* getObject() const {return m_object;}
		QMetaProperty getMetaProperty() const {return m_metaProperty;}
		QVariant getValue() const {return m_value;}

		void setValue(const QVariant &value) {setValue(value, value.toString());}
		void setValue(const QVariant &value, const QString &displayText);
	};

    explicit PropertyEditor(QWidget *parent = 0);

private:
	void _addProperty(const char *className, const char *typeName, const char *key, ValueItem *valueItem);

signals:

public slots:
	void setObject(QObject *object);
};

#endif // PROPERTYEDITOR_H
