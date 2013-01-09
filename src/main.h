/*
   main.h
   chntpw-gui
   By Trevor Bergeron (mallegonian@gmail.com) and Sean Buckley
   This program is copyright 2013, and is licensed under the terms of the GNU General Public License.
*/

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

