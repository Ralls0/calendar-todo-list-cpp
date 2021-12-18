/**
 *
 * @author  Marco Manco
 * @date    04/12/21.
 * @file    Calendar.h
 * @brief
 *
 */

#ifndef CALENDAR_TODO_LIST_CPP_CALENDAR_H
#define CALENDAR_TODO_LIST_CPP_CALENDAR_H

#include "../../CalendarEvent/CalendarEvent.h"
#include "../../CalendarManager/CalendarManager.h"
#include "../../Utils/ColorUtils.h"
#include "../NewEvent/NewEventDialog.h"
#include "./CustomDialog.h"
#include "./DateUtil.h"
#include "./QFrameExtended.h"
#include "./QLabelEvent.h"
#include "./QPushButtonExtended.h"
#include "./QWidgetExtended.h"
#include <QApplication>
#include <QCalendarWidget>
#include <QCheckBox>
#include <QComboBox>
#include <QDateEdit>
#include <QDebug>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLocale>
#include <QMainWindow>
#include <QPushButton>
#include <QTableWidget>
#include <QTextCharFormat>
#include <QWidget>
#include <iostream>

/* Gets the current month displayed using an hack. Infact, the cell in the
 * middle will have always a value setted. This should be used when you don't
 * care about the day */
#define CURRENT_MONTH *this->frames[21]->getDate()

class MainCalendar : public QWidget {
  Q_OBJECT

public:
  MainCalendar(QWidget *parent = nullptr);
  ~MainCalendar();

signals:
  void calendarDateChanged(QDate newDate);
  void shownCalendarChanged(const QList<QObject *> &eventList);

public slots:
  void on_back_button_click();
  void on_next_button_click();
  void on_event_click(QLabelEvent *label_event, Qt::MouseButton button);
  void setCalendarList(QList<QObject *> t);
  void updateListOfEvents(const QList<QObject *> &eventList);

private:
  QList<QString> *_listCalendar;
  QList<QCheckBox *> *_checkList;
  WindowStyle _colorStyle;
  void on_button_edit_click(QPushButtonExtended *d);
  void filterCalendar();
  void on_button_extended_click(int index);
  void display_days(Date date);
  void remove_events_from_all_frames();
  void remove_events_from_frame(int i);
  // QLabelEvent *createLabelEvent(Event *event);
  QLabelEvent *createLabelEvent(CalendarEvent *event);
  QFrameExtended *createQFrameExtended(Date *date);
  QFrameExtended *frames[42]; // I have a 7x7 grid, but without consider the
                              // first row I've a total of 6x7 cells
  QHBoxLayout *_calList;
  QHBoxLayout *_calListLayout;
  QList<QObject *> _eventList;
  QVBoxLayout *layout;
  QCalendarWidget *calendar;
  QLabel *label_date; // la label centrale
};

#endif // CALENDAR_TODO_LIST_CPP_CALENDAR_H
