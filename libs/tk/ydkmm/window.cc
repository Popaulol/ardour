// Generated by gmmproc 2.45.3 -- DO NOT MODIFY!

#undef GDK_DISABLE_DEPRECATED
 

#include <glibmm.h>

#include <gdkmm/window.h>
#include <gdkmm/private/window_p.h>


// -*- c++ -*-
/* $Id: window.ccg,v 1.7 2004/03/09 17:36:25 murrayc Exp $ */

/* Copyright 1998-2002 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <gdk/gdk.h>
#include <gdkmm/pixmap.h>
#include <gdkmm/cursor.h>
#include <gdkmm/types.h>


namespace Gdk
{

Window::Window(const Glib::RefPtr<Window>& parent, GdkWindowAttr* attributes, int attributes_mask)
:
  Drawable((GdkDrawable*) gdk_window_new(Glib::unwrap(parent), attributes, attributes_mask))
{
  //GdkWindow is X11/win32-specific, so we probably can't derived our own GType.
}

void Window::set_cursor()
{
  gdk_window_set_cursor(gobj(), 0);
}

GrabStatus Window::pointer_grab(bool owner_events, EventMask event_mask, const Cursor& cursor, guint32 timestamp)
{
  return ((GrabStatus)(gdk_pointer_grab(gobj(), static_cast<int>(owner_events), ((GdkEventMask)(event_mask)), 0, (cursor).gobj_copy(), timestamp)));
}

GrabStatus Window::pointer_grab(bool owner_events, EventMask event_mask, guint32 timestamp)
{
  return ((GrabStatus)(gdk_pointer_grab(gobj(), static_cast<int>(owner_events), ((GdkEventMask)(event_mask)), 0, 0, timestamp)));
}

//static
void Window::unset_sm_client_id()
{
  gdk_set_sm_client_id(0 /* see GDK docs */);
}

void Window::set_icon(const Glib::RefPtr<Window>& icon_window, const Glib::RefPtr<Pixmap>& pixmap)
{
  gdk_window_set_icon(gobj(), icon_window->gobj(), pixmap->gobj(), 0); /* See GDK docs */  
}
  
void Window::unset_icon()
{
  gdk_window_set_icon(gobj(), 0, 0, 0); /* See GDK docs */
}

void Window::unset_shape_combine_mask()
{
  gdk_window_shape_combine_mask(gobj(), 0, 0, 0); //See GDK docs.
} 

void Window::get_internal_paint_info(Glib::RefPtr<Drawable>& real_drawable, int& x_offset, int& y_offset) const
{
  GdkDrawable* temp_drawable = 0;
  gdk_window_get_internal_paint_info(const_cast<GdkWindow*>(gobj()), &temp_drawable, &x_offset, &y_offset);
  real_drawable = Glib::wrap(temp_drawable);
}

void Window::unset_back_pixmap()
{
  gdk_window_set_back_pixmap(gobj(), NULL, FALSE);
}

void Window::invalidate(bool invalidate_children)
{
  gdk_window_invalidate_rect(gobj(), NULL, invalidate_children);
}

void Window::restack(bool above)
{
  gdk_window_restack(gobj(), NULL, above);
}

Glib::RefPtr<DragContext> Window::drag_begin(const Glib::StringArrayHandle& targets)
{
  Glib::RefPtr<DragContext> result;
  
  //Put it into a real container that we can use:
  std::vector<Glib::ustring> targets_copy = targets;
   
  //Create GList from target strings:
  if(!targets_copy.empty())
  {
    GList* list = 0;
    
    for(guint i = 0; i < targets_copy.size(); ++i)
    {
      GdkAtom atom = Gdk::AtomString::to_c_type(targets_copy[i]);
      list = g_list_append (list, GUINT_TO_POINTER (atom));
    }

    result = Glib::wrap(gdk_drag_begin(gobj(), list), true);

    g_list_free(list);
  }

  return result;
}


} // namespace Gdk


namespace
{
} // anonymous namespace

// static
GType Glib::Value<Gdk::EventMask>::value_type()
{
  return gdk_event_mask_get_type();
}

// static
GType Glib::Value<Gdk::WindowState>::value_type()
{
  return gdk_window_state_get_type();
}

// static
GType Glib::Value<Gdk::WindowType>::value_type()
{
  return gdk_window_type_get_type();
}

// static
GType Glib::Value<Gdk::WindowAttributesType>::value_type()
{
  return gdk_window_attributes_type_get_type();
}

// static
GType Glib::Value<Gdk::WindowHints>::value_type()
{
  return gdk_window_hints_get_type();
}

// static
GType Glib::Value<Gdk::WindowTypeHint>::value_type()
{
  return gdk_window_type_hint_get_type();
}

// static
GType Glib::Value<Gdk::WMDecoration>::value_type()
{
  return gdk_wm_decoration_get_type();
}

// static
GType Glib::Value<Gdk::WMFunction>::value_type()
{
  return gdk_wm_function_get_type();
}

// static
GType Glib::Value<Gdk::WindowEdge>::value_type()
{
  return gdk_window_edge_get_type();
}

// static
GType Glib::Value<Gdk::Gravity>::value_type()
{
  return gdk_gravity_get_type();
}

// static
GType Glib::Value<Gdk::GrabStatus>::value_type()
{
  return gdk_grab_status_get_type();
}


namespace Glib
{

Glib::RefPtr<Gdk::Window> wrap(GdkWindowObject* object, bool take_copy)
{
  return Glib::RefPtr<Gdk::Window>( dynamic_cast<Gdk::Window*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gdk
{


/* The *_Class implementation: */

const Glib::Class& Window_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Window_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gdk_window_object_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void Window_Class::class_init_function(void* g_class, void* class_data)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* Window_Class::wrap_new(GObject* object)
{
  return new Window((GdkWindow*)object);
}


/* The implementation: */

GdkWindow* Window::gobj_copy()
{
  reference();
  return gobj();
}

Window::Window(const Glib::ConstructParams& construct_params)
:
  Gdk::Drawable(construct_params)
{

}

Window::Window(GdkWindow* castitem)
:
  Gdk::Drawable((GdkDrawable*)(castitem))
{}


Window::~Window()
{}


Window::CppClassType Window::window_class_; // initialize static member

GType Window::get_type()
{
  return window_class_.init().get_type();
}


GType Window::get_base_type()
{
  return gdk_window_object_get_type();
}


Glib::RefPtr<Window> Window::create(const Glib::RefPtr<Window>& parent, GdkWindowAttr* attributes, int attributes_mask)
{
  return Glib::RefPtr<Window>( new Window(parent, attributes, attributes_mask) );
}

WindowType Window::get_window_type() const
{
  return ((WindowType)(gdk_window_get_window_type(const_cast<GdkWindow*>(gobj()))));
}

Glib::RefPtr<Visual> Window::get_visual()
{
  Glib::RefPtr<Visual> retvalue = Glib::wrap(gdk_window_get_visual(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const Visual> Window::get_visual() const
{
  return const_cast<Window*>(this)->get_visual();
}

Glib::RefPtr<Screen> Window::get_screen()
{
  Glib::RefPtr<Screen> retvalue = Glib::wrap(gdk_window_get_screen(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const Screen> Window::get_screen() const
{
  return const_cast<Window*>(this)->get_screen();
}

Glib::RefPtr<Display> Window::get_display()
{
  Glib::RefPtr<Display> retvalue = Glib::wrap(gdk_window_get_display(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const Display> Window::get_display() const
{
  return const_cast<Window*>(this)->get_display();
}

void Window::show()
{
  gdk_window_show(gobj());
}

void Window::hide()
{
  gdk_window_hide(gobj());
}

void Window::withdraw()
{
  gdk_window_withdraw(gobj());
}

void Window::show_unraised()
{
  gdk_window_show_unraised(gobj());
}

void Window::move(int x, int y)
{
  gdk_window_move(gobj(), x, y);
}

void Window::resize(int width, int height)
{
  gdk_window_resize(gobj(), width, height);
}

void Window::move_resize(int x, int y, int width, int height)
{
  gdk_window_move_resize(gobj(), x, y, width, height);
}

void Window::reparent(const Glib::RefPtr<Window>& new_parent, int x, int y)
{
  gdk_window_reparent(gobj(), Glib::unwrap(new_parent), x, y);
}

void Window::clear()
{
  gdk_window_clear(gobj());
}

void Window::clear_area(int x, int y, int width, int height)
{
  gdk_window_clear_area(gobj(), x, y, width, height);
}

void Window::clear_area_e(int x, int y, int width, int height)
{
  gdk_window_clear_area_e(gobj(), x, y, width, height);
}

void Window::raise()
{
  gdk_window_raise(gobj());
}

void Window::lower()
{
  gdk_window_lower(gobj());
}

void Window::restack(const Glib::RefPtr<Window>& sibling, bool above)
{
  gdk_window_restack(gobj(), Glib::unwrap(sibling), static_cast<int>(above));
}

void Window::focus(guint32 timestamp)
{
  gdk_window_focus(gobj(), timestamp);
}

void Window::set_user_data(gpointer user_data)
{
  gdk_window_set_user_data(gobj(), user_data);
}

void Window::set_override_redirect(bool override_redirect)
{
  gdk_window_set_override_redirect(gobj(), static_cast<int>(override_redirect));
}

void Window::add_filter(GdkFilterFunc function, gpointer data)
{
  gdk_window_add_filter(gobj(), function, data);
}

void Window::remove_filter(GdkFilterFunc function, gpointer data)
{
  gdk_window_remove_filter(gobj(), function, data);
}

void Window::scroll(int dx, int dy)
{
  gdk_window_scroll(gobj(), dx, dy);
}

void Window::move_region(const Region& region, int dx, int dy)
{
  gdk_window_move_region(gobj(), (region).gobj(), dx, dy);
}

bool Window::ensure_native()
{
  return gdk_window_ensure_native(gobj());
}

void Window::shape_combine_mask(const Glib::RefPtr<Bitmap>& mask, int x, int y)
{
  gdk_window_shape_combine_mask(gobj(), Glib::unwrap(mask), x, y);
}

void Window::shape_combine_region(const Region& shape_region, int offset_x, int offset_y)
{
  gdk_window_shape_combine_region(gobj(), (shape_region).gobj(), offset_x, offset_y);
}

void Window::set_child_shapes()
{
  gdk_window_set_child_shapes(gobj());
}

bool Window::get_composited() const
{
  return gdk_window_get_composited(const_cast<GdkWindow*>(gobj()));
}

void Window::set_composited(bool composited)
{
  gdk_window_set_composited(gobj(), static_cast<int>(composited));
}

void Window::merge_child_shapes()
{
  gdk_window_merge_child_shapes(gobj());
}

void Window::input_shape_combine_mask(const Glib::RefPtr<Bitmap>& mask, int x, int y)
{
  gdk_window_input_shape_combine_mask(gobj(), Glib::unwrap(mask), x, y);
}

void Window::input_shape_combine_region(const Region& shape_region, int offset_x, int offset_y)
{
  gdk_window_input_shape_combine_region(gobj(), (shape_region).gobj(), offset_x, offset_y);
}

void Window::set_child_input_shapes()
{
  gdk_window_set_child_input_shapes(gobj());
}

void Window::merge_child_input_shapes()
{
  gdk_window_merge_child_input_shapes(gobj());
}

bool Window::is_visible() const
{
  return gdk_window_is_visible(const_cast<GdkWindow*>(gobj()));
}

bool Window::is_viewable() const
{
  return gdk_window_is_viewable(const_cast<GdkWindow*>(gobj()));
}

bool Window::is_input_only() const
{
  return gdk_window_is_input_only(const_cast<GdkWindow*>(gobj()));
}

bool Window::is_shaped() const
{
  return gdk_window_is_shaped(const_cast<GdkWindow*>(gobj()));
}

WindowState Window::get_state() const
{
  return ((WindowState)(gdk_window_get_state(const_cast<GdkWindow*>(gobj()))));
}

bool Window::set_static_gravities(bool use_static)
{
  return gdk_window_set_static_gravities(gobj(), static_cast<int>(use_static));
}

bool Window::has_native() const
{
  return gdk_window_has_native(const_cast<GdkWindow*>(gobj()));
}

void Window::set_type_hint(WindowTypeHint hint)
{
  gdk_window_set_type_hint(gobj(), ((GdkWindowTypeHint)(hint)));
}

WindowTypeHint Window::get_type_hint()
{
  return ((WindowTypeHint)(gdk_window_get_type_hint(gobj())));
}

bool Window::get_modal_hint() const
{
  return gdk_window_get_modal_hint(const_cast<GdkWindow*>(gobj()));
}

void Window::set_modal_hint(bool modal)
{
  gdk_window_set_modal_hint(gobj(), static_cast<int>(modal));
}

void Window::set_geometry_hints(const Geometry& geometry, WindowHints geom_mask)
{
  gdk_window_set_geometry_hints(gobj(), &(geometry), ((GdkWindowHints)(geom_mask)));
}

void Window::set_sm_client_id(const Glib::ustring& sm_client_id)
{
  gdk_set_sm_client_id(sm_client_id.c_str());
}

void Window::begin_paint_rect(Rectangle& rectangle)
{
  gdk_window_begin_paint_rect(gobj(), (rectangle).gobj());
}

void Window::begin_paint_region(const Region& region)
{
  gdk_window_begin_paint_region(gobj(), (region).gobj());
}

void Window::end_paint()
{
  gdk_window_end_paint(gobj());
}

void Window::flush()
{
  gdk_window_flush(gobj());
}

void Window::set_title(const Glib::ustring& title)
{
  gdk_window_set_title(gobj(), title.c_str());
}

void Window::set_role(const Glib::ustring& role)
{
  gdk_window_set_role(gobj(), role.c_str());
}

void Window::set_startup_id(const Glib::ustring& startup_id)
{
  gdk_window_set_startup_id(gobj(), startup_id.c_str());
}

void Window::set_transient_for(const Glib::RefPtr<Window>& parent)
{
  gdk_window_set_transient_for(gobj(), Glib::unwrap(parent));
}

void Window::set_background(const Color& color)
{
  gdk_window_set_background(gobj(), (color).gobj());
}

void Window::set_back_pixmap(const Glib::RefPtr<Pixmap>& pixmap, bool parent_relative)
{
  gdk_window_set_back_pixmap(gobj(), Glib::unwrap(pixmap), static_cast<int>(parent_relative));
}

::Cairo::RefPtr< ::Cairo::Pattern> Window::get_background_pattern()
{
  return ::Cairo::RefPtr< ::Cairo::Pattern>(new Cairo::Pattern(gdk_window_get_background_pattern(gobj()), false /* take reference */));
}

::Cairo::RefPtr<const ::Cairo::Pattern> Window::get_background_pattern() const
{
  return ::Cairo::RefPtr<const ::Cairo::Pattern>(new Cairo::Pattern(gdk_window_get_background_pattern(const_cast<GdkWindow*>(gobj())), false /* take reference */));
}

void Window::set_cursor(const Cursor& cursor)
{
  gdk_window_set_cursor(gobj(), const_cast<GdkCursor*>((cursor).gobj()));
}

void Window::get_user_data(gpointer* data)
{
  gdk_window_get_user_data(gobj(), data);
}

void Window::get_geometry(int& x, int& y, int& width, int& height, int& depth) const
{
  gdk_window_get_geometry(const_cast<GdkWindow*>(gobj()), &(x), &(y), &(width), &(height), &(depth));
}

int Window::get_width() const
{
  return gdk_window_get_width(const_cast<GdkWindow*>(gobj()));
}

int Window::get_height() const
{
  return gdk_window_get_height(const_cast<GdkWindow*>(gobj()));
}

void Window::get_position(int& x, int& y) const
{
  gdk_window_get_position(const_cast<GdkWindow*>(gobj()), &(x), &(y));
}

int Window::get_origin(int& x, int& y) const
{
  return gdk_window_get_origin(const_cast<GdkWindow*>(gobj()), &(x), &(y));
}

void Window::get_root_coords(int x, int y, int& root_x, int& root_y)
{
  gdk_window_get_root_coords(gobj(), x, y, &(root_x), &(root_y));
}

void Window::coords_to_parent(double x, double y, double& parent_x, double& parent_y)
{
  gdk_window_coords_to_parent(gobj(), x, y, &(parent_x), &(parent_y));
}

void Window::coords_from_parent(double parent_x, double parent_y, double& x, double& y)
{
  gdk_window_coords_from_parent(gobj(), parent_x, parent_y, &(x), &(y));
}

void Window::get_root_origin(int& x, int& y) const
{
  gdk_window_get_root_origin(const_cast<GdkWindow*>(gobj()), &(x), &(y));
}

void Window::get_frame_extents(Rectangle& rect)
{
  gdk_window_get_frame_extents(gobj(), (rect).gobj());
}

Glib::RefPtr<Window> Window::get_pointer(int& x, int& y, ModifierType& mask)
{
  Glib::RefPtr<Window> retvalue = Glib::wrap((GdkWindowObject*)(gdk_window_get_pointer(gobj(), &(x), &(y), ((GdkModifierType*) &(mask)))));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<Window> Window::get_parent()
{
  Glib::RefPtr<Window> retvalue = Glib::wrap((GdkWindowObject*)(gdk_window_get_parent(gobj())));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const Window> Window::get_parent() const
{
  return const_cast<Window*>(this)->get_parent();
}

Glib::RefPtr<Window> Window::get_toplevel()
{
  Glib::RefPtr<Window> retvalue = Glib::wrap((GdkWindowObject*)(gdk_window_get_toplevel(gobj())));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const Window> Window::get_toplevel() const
{
  return const_cast<Window*>(this)->get_toplevel();
}

Glib::RefPtr<Window> Window::get_effective_parent()
{
  Glib::RefPtr<Window> retvalue = Glib::wrap((GdkWindowObject*)(gdk_window_get_effective_parent(gobj())));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const Window> Window::get_effective_parent() const
{
  return const_cast<Window*>(this)->get_effective_parent();
}

Glib::RefPtr<Window> Window::get_effective_toplevel()
{
  Glib::RefPtr<Window> retvalue = Glib::wrap((GdkWindowObject*)(gdk_window_get_effective_toplevel(gobj())));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::ListHandle< Glib::RefPtr<Window> > Window::get_children()
{
  return Glib::ListHandle< Glib::RefPtr<Window> >(gdk_window_get_children(gobj()), Glib::OWNERSHIP_SHALLOW);
}

Glib::ListHandle< Glib::RefPtr<const Window> > Window::get_children() const
{
  return Glib::ListHandle< Glib::RefPtr<const Window> >(gdk_window_get_children(const_cast<GdkWindow*>(gobj())), Glib::OWNERSHIP_SHALLOW);
}

EventMask Window::get_events() const
{
  return ((EventMask)(gdk_window_get_events(const_cast<GdkWindow*>(gobj()))));
}

void Window::set_events(EventMask event_mask)
{
  gdk_window_set_events(gobj(), ((GdkEventMask)(event_mask)));
}

void Window::set_icon_list(const Glib::ListHandle< Glib::RefPtr<Gdk::Pixbuf> >& pixbufs)
{
  gdk_window_set_icon_list(gobj(), pixbufs.data());
}

void Window::set_icon(const Glib::RefPtr<Window>& icon_window, const Glib::RefPtr<Pixmap>& pixmap, const Glib::RefPtr<Bitmap>& mask)
{
  gdk_window_set_icon(gobj(), Glib::unwrap(icon_window), Glib::unwrap(pixmap), Glib::unwrap(mask));
}

void Window::set_icon_name(const Glib::ustring& name)
{
  gdk_window_set_icon_name(gobj(), name.c_str());
}

void Window::set_group(const Glib::RefPtr<Window>& leader)
{
  gdk_window_set_group(gobj(), Glib::unwrap(leader));
}

Glib::RefPtr<Window> Window::get_group()
{
  return Glib::wrap((GdkWindowObject*)(gdk_window_get_group(gobj())));
}

Glib::RefPtr<const Window> Window::get_group() const
{
  return const_cast<Window*>(this)->get_group();
}

void Window::set_decorations(WMDecoration decorations)
{
  gdk_window_set_decorations(gobj(), ((GdkWMDecoration)(decorations)));
}

bool Window::get_decorations(WMDecoration& decorations) const
{
  return gdk_window_get_decorations(const_cast<GdkWindow*>(gobj()), ((GdkWMDecoration*) &(decorations)));
}

void Window::set_functions(WMFunction functions)
{
  gdk_window_set_functions(gobj(), ((GdkWMFunction)(functions)));
}

#ifndef GDKMM_DISABLE_DEPRECATED
G_GNUC_BEGIN_IGNORE_DEPRECATIONS
Glib::ListHandle< Glib::RefPtr<Window> > Window::get_toplevels()
{
  return Glib::ListHandle< Glib::RefPtr<Window> >(gdk_window_get_toplevels(), Glib::OWNERSHIP_SHALLOW);
}
G_GNUC_END_IGNORE_DEPRECATIONS
#endif // GDKMM_DISABLE_DEPRECATED

::Cairo::RefPtr< ::Cairo::Surface> Window::create_similar_surface(::Cairo::Content content, int width, int height)
{
  return ::Cairo::RefPtr< ::Cairo::Surface>(new Cairo::Surface(gdk_window_create_similar_surface(gobj(), (cairo_content_t)(content), width, height), false /* take reference */));
}

void Window::beep()
{
  gdk_window_beep(gobj());
}

void Window::iconify()
{
  gdk_window_iconify(gobj());
}

void Window::deiconify()
{
  gdk_window_deiconify(gobj());
}

void Window::stick()
{
  gdk_window_stick(gobj());
}

void Window::unstick()
{
  gdk_window_unstick(gobj());
}

void Window::maximize()
{
  gdk_window_maximize(gobj());
}

void Window::unmaximize()
{
  gdk_window_unmaximize(gobj());
}

void Window::register_dnd()
{
  gdk_window_register_dnd(gobj());
}

void Window::begin_resize_drag(WindowEdge edge, int button, int root_x, int root_y, guint32 timestamp)
{
  gdk_window_begin_resize_drag(gobj(), ((GdkWindowEdge)(edge)), button, root_x, root_y, timestamp);
}

void Window::begin_move_drag(int button, int root_x, int root_y, guint32 timestamp)
{
  gdk_window_begin_move_drag(gobj(), button, root_x, root_y, timestamp);
}

void Window::invalidate_rect(const Rectangle& rect, bool invalidate_children)
{
  gdk_window_invalidate_rect(gobj(), (rect).gobj(), static_cast<int>(invalidate_children));
}

void Window::invalidate_region(const Region& region, bool invalidate_children)
{
  gdk_window_invalidate_region(gobj(), (region).gobj(), static_cast<int>(invalidate_children));
}

Region Window::get_update_area()
{
  return Region(gdk_window_get_update_area(gobj()));
}

void Window::freeze_updates()
{
  gdk_window_freeze_updates(gobj());
}

void Window::thaw_updates()
{
  gdk_window_thaw_updates(gobj());
}

void Window::process_all_updates()
{
  gdk_window_process_all_updates();
}

void Window::process_updates(bool update_children)
{
  gdk_window_process_updates(gobj(), static_cast<int>(update_children));
}

void Window::set_debug_updates(bool setting)
{
  gdk_window_set_debug_updates(static_cast<int>(setting));
}

void Window::constrain_size(const Geometry& geometry, guint flags, int width, int height, int& new_width, int& new_height)
{
  gdk_window_constrain_size(const_cast<GdkGeometry*>(&(geometry)), flags, width, height, &(new_width), &(new_height));
}

void Window::enable_synchronized_configure()
{
  gdk_window_enable_synchronized_configure(gobj());
}

void Window::configure_finished()
{
  gdk_window_configure_finished(gobj());
}

void Window::set_skip_taskbar_hint(bool skips_taskbar)
{
  gdk_window_set_skip_taskbar_hint(gobj(), static_cast<int>(skips_taskbar));
}

void Window::set_skip_pager_hint(bool skips_pager)
{
  gdk_window_set_skip_pager_hint(gobj(), static_cast<int>(skips_pager));
}

void Window::set_urgency_hint(bool urgent)
{
  gdk_window_set_urgency_hint(gobj(), static_cast<int>(urgent));
}

void Window::fullscreen()
{
  gdk_window_fullscreen(gobj());
}

void Window::unfullscreen()
{
  gdk_window_unfullscreen(gobj());
}

GrabStatus Window::pointer_grab(bool owner_events, EventMask event_mask, const Glib::RefPtr<const Window>& confine_to, const Cursor& cursor, guint32 time_)
{
  return ((GrabStatus)(gdk_pointer_grab(gobj(), static_cast<int>(owner_events), ((GdkEventMask)(event_mask)), const_cast<GdkWindow*>(Glib::unwrap<Gdk::Window>(confine_to)), const_cast<GdkCursor*>((cursor).gobj()), time_)));
}

void Window::pointer_ungrab(guint32 timestamp)
{
  gdk_pointer_ungrab(timestamp);
}

GrabStatus Window::keyboard_grab(bool owner_events, guint32 timestamp)
{
  return ((GrabStatus)(gdk_keyboard_grab(gobj(), static_cast<int>(owner_events), timestamp)));
}

void Window::keyboard_ungrab(guint32 timestamp)
{
  gdk_keyboard_ungrab(timestamp);
}

void Window::set_keep_above(bool setting)
{
  gdk_window_set_keep_above(gobj(), static_cast<int>(setting));
}

void Window::set_keep_below(bool setting)
{
  gdk_window_set_keep_below(gobj(), static_cast<int>(setting));
}

void Window::set_opacity(double opacity)
{
  gdk_window_set_opacity(gobj(), opacity);
}

bool Window::get_accept_focus() const
{
  return gdk_window_get_accept_focus(const_cast<GdkWindow*>(gobj()));
}

void Window::set_accept_focus(bool accept_focus)
{
  gdk_window_set_accept_focus(gobj(), static_cast<int>(accept_focus));
}

bool Window::get_focus_on_map() const
{
  return gdk_window_get_focus_on_map(const_cast<GdkWindow*>(gobj()));
}

void Window::set_focus_on_map(bool focus_on_map)
{
  gdk_window_set_focus_on_map(gobj(), static_cast<int>(focus_on_map));
}

Glib::RefPtr<Window> Window::get_default_root_window()
{

  Glib::RefPtr<Window> retvalue = Glib::wrap((GdkWindowObject*)(gdk_get_default_root_window()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us
  return retvalue;
}

Glib::RefPtr<Pixmap> Window::get_offscreen_pixmap()
{
  Glib::RefPtr<Pixmap> retvalue = Glib::wrap((GdkPixmapObject*)(gdk_offscreen_window_get_pixmap(gobj())));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const Pixmap> Window::get_offscreen_pixmap() const
{
  return const_cast<Window*>(this)->get_offscreen_pixmap();
}

Glib::RefPtr<Window> Window::get_offscreen_embedder()
{
  Glib::RefPtr<Window> retvalue = Glib::wrap((GdkWindowObject*)(gdk_offscreen_window_get_embedder(gobj())));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const Window> Window::get_offscreen_embedder() const
{
  return const_cast<Window*>(this)->get_offscreen_embedder();
}

void Window::set_offscreen_embedder(const Glib::RefPtr<Window>& embedder)
{
  gdk_offscreen_window_set_embedder(gobj(), Glib::unwrap(embedder));
}

void Window::redirect_to_drawable(const Glib::RefPtr<Drawable>& drawable, int src_x, int src_y, int dest_x, int dest_y, int width, int height)
{
  gdk_window_redirect_to_drawable(gobj(), Glib::unwrap(drawable), src_x, src_y, dest_x, dest_y, width, height);
}

void Window::remove_redirection()
{
  gdk_window_remove_redirection(gobj());
}

void Window::geometry_changed()
{
  gdk_window_geometry_changed(gobj());
}


} // namespace Gdk

