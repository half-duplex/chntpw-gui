/**
  src/main.h
  This file is part of chntpw-gui, a graphical frontend to chntpw.
  Copyright (C) 2013 Trevor Bergeron

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program. If not, see <http://www.gnu.org/licenses/>.
**/

#include <iostream>
#include <blkid.h>
#include <sys/mount.h>
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/label.h>
#include <gtkmm/box.h>
#include <gtkmm/stock.h>
#include <gtkmm/entry.h>
#include <gtkmm/liststore.h>
#include <gtkmm/comboboxtext.h>

pid_t popen2(const char *command, int *infp, int *outfp);

class t_chntpw : public Gtk::Window {
    public:
        t_chntpw();
        virtual ~t_chntpw();

    protected:
        // Functions
        void go();
        void exit();
        void on_drive_change();

        // Controls
        Gtk::Box m_box_everything, m_box_drive, m_box_user, m_box_password, m_box_buttons;
        Gtk::Label m_lbl_drive, m_lbl_user, m_lbl_password;
        Gtk::ComboBox m_cmb_drive, m_cmb_user;
        Gtk::Entry m_psw_password;
        Gtk::Button m_btn_go, m_btn_exit;
        // Tree Model Columns
        class ModelColumns : public Gtk::TreeModel::ColumnRecord {
            public:
                ModelColumns(){
                    add(m_col_dev);
                    add(m_col_name);
                }
                Gtk::TreeModelColumn<Glib::ustring> m_col_dev;
                Gtk::TreeModelColumn<Glib::ustring> m_col_name;
        };
        ModelColumns m_cols_dev, m_cols_user;
        Glib::RefPtr<Gtk::ListStore> m_refTreeModel_dev, m_refTreeModel_user;

        // libblkid
        blkid_dev *dev_target;
        
};

/* vim: set ts=4 sw=4 tw=0 et :*/
