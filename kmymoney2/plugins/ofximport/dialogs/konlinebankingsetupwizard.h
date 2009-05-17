/***************************************************************************
                          konlinebankingsetupwizard.h
                             -------------------
    begin                : Sat Jan 7 2006
    copyright            : (C) 2006 by Ace Jones
    email                : acejones@users.sourceforge.net
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef KONLINEBANKINGSETUPWIZARD_H
#define KONLINEBANKINGSETUPWIZARD_H

// ----------------------------------------------------------------------------
// Library Includes

#include <libofx/libofx.h>

// ----------------------------------------------------------------------------
// QT Includes

#include <qwidget.h>
#include <q3valuelist.h>
#include <q3listview.h>

// ----------------------------------------------------------------------------
// KDE Includes

// ----------------------------------------------------------------------------
// Project Includes

#include "ui_konlinebankingsetupdecl.h"
#include <mymoneykeyvaluecontainer.h>
class OfxAppVersion;
class OfxHeaderVersion;

/**
  * @author Ace Jones
  */

/**
  * This class implementes a wizard for setting up an existing account
  * with online banking.
  *
  * The user is asked to choose his bank from the supported bank, and
  * his account.
  *
  * Currently works only with OFX Direct Connect, but I imagined that
  * other protocols could be included here.  To accomodate this, we'd
  * add another page at the start of the wizard to ask which protocol
  * they wanted.
  *
  */

class KOnlineBankingSetupDecl : public Q3Wizard, public Ui::KOnlineBankingSetupDecl
{
public:
  KOnlineBankingSetupDecl( QWidget *parent ) : Q3Wizard( parent ) {
    setupUi( this );
  }
};

class KOnlineBankingSetupWizard : public KOnlineBankingSetupDecl
{
  Q_OBJECT
public:
  class ListViewItem: public MyMoneyKeyValueContainer, public Q3ListViewItem
  {
  public:
    ListViewItem( Q3ListView* parent, const MyMoneyKeyValueContainer& kvps );
    virtual void x(void);
  };

  KOnlineBankingSetupWizard(QWidget *parent=0);
  ~KOnlineBankingSetupWizard();

  bool chosenSettings( MyMoneyKeyValueContainer& settings );

  bool isInit(void) const { return m_fInit; }

public slots:
  void next();

protected:
  bool finishAccountPage(void);
  bool finishLoginPage(void);
  bool finishFiPage(void);
  bool post(const char* request, const char* url,const char* filename);

  static int ofxAccountCallback(struct OfxAccountData data, void * pv);
  static int ofxStatusCallback(struct OfxStatusData data, void * pv);

private:
  /// \internal d-pointer class.
  class Private;
  /// \internal d-pointer instance.
  Private* const d;

  Q3ValueList<OfxFiServiceInfo> m_bankInfo;
  Q3ValueList<OfxFiServiceInfo>::const_iterator m_it_info;
  bool m_fDone;
  bool m_fInit;
  OfxAppVersion* m_appId;
  OfxHeaderVersion* m_headerVersion;
};

#endif
// vim:cin:si:ai:et:ts=2:sw=2:
