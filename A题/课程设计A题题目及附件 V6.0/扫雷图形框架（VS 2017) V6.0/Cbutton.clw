; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCbuttonView
LastTemplate=CButton
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Cbutton.h"
LastPage=0

ClassCount=6
Class1=CCbuttonApp
Class2=CCbuttonDoc
Class3=CCbuttonView
Class4=CMainFrame

ResourceCount=3
Resource1=IDR_MENU1
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Class6=CHideButton
Resource3=IDD_ABOUTBOX

[CLS:CCbuttonApp]
Type=0
HeaderFile=Cbutton.h
ImplementationFile=Cbutton.cpp
Filter=N
LastObject=CCbuttonApp

[CLS:CCbuttonDoc]
Type=0
HeaderFile=CbuttonDoc.h
ImplementationFile=CbuttonDoc.cpp
Filter=N
LastObject=CCbuttonDoc

[CLS:CCbuttonView]
Type=0
HeaderFile=CbuttonView.h
ImplementationFile=CbuttonView.cpp
Filter=M
BaseClass=CView
VirtualFilter=VWC
LastObject=ID_MACHINE


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=Cbutton.cpp
ImplementationFile=Cbutton.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16

[ACL:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[MNU:IDR_MENU1]
Type=1
Class=CCbuttonView
Command1=ID_MENU_NEW
Command2=ID_MACHINE
Command3=ID_MENU_OUT
Command4=ID_MENU_CAPTION
CommandCount=4

[CLS:CHideButton]
Type=0
HeaderFile=HideButton.h
ImplementationFile=HideButton.cpp
BaseClass=CButton
Filter=W
LastObject=CHideButton

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

