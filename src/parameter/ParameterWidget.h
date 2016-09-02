/*
 *  OpenSCAD (www.openscad.org)
 *  Copyright (C) 2009-2014 Clifford Wolf <clifford@clifford.at> and
 *                          Marius Kintel <marius@kintel.net>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  As a special exception, you have permission to link this program
 *  with the CGAL library and distribute executables, as long as you
 *  follow the requirements of the GNU GPL in regard to all of the
 *  software in the executable aside from CGAL.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */
#pragma once

#include <QTimer>


#include "parameterextractor.h"
#include "ui_ParameterWidget.h"
#include "groupwidget.h"
#include "parameterset.h"

class ParameterWidget : public QWidget, public Ui::ParameterWidget, public ParameterExtractor, public ParameterSet
{
	Q_OBJECT
private:
    typedef std::map<std::string,groupInst > group_map;
    group_map groupMap;
    typedef enum { UNDEFINED, COMBOBOX, SLIDER, CHECKBOX, TEXT, NUMBER, VECTOR } parameter_type_t;
    QTimer autoPreviewTimer;
    bool descriptionShow;
    QVBoxLayout * anyLayout;
    string jsonFile;
    bool anyfocused;
    ParameterVirtualWidget *entryToFocus;


public:
    ParameterWidget(QWidget *parent = 0);
    virtual ~ParameterWidget();
    void setFile(QString jsonFile);

protected slots:
    void onValueChanged();
    void onPreviewTimerElapsed();
    void onDescriptionShow();
    void onSetChanged(int idx);
    void onSetAdd();
    void onSetDelete();
    void resetParameter();

signals:
    void previewRequested();

protected:
    void connectWidget();
    void begin();
    void addEntry(class ParameterVirtualWidget *entry);
    void end();
    void clear();
    void AddParameterWidget(string parameterName);
    void setComboBoxForSet();
    void applyParameterSet(string setName);
    void updateParameterSet(string setName);
};
