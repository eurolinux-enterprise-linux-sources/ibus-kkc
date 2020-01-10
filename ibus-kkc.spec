Name:		ibus-kkc
Version:	1.5.18
Release:	7%{?dist}
Summary:	Japanese Kana Kanji input method for ibus

Group:		System Environment/Libraries
License:	GPLv2+
URL:		https://bitbucket.org/libkkc
Source0:	https://bitbucket.org/libkkc/ibus-kkc/downloads/%{name}-%{version}.tar.gz
Patch0:		ibus-kkc-ignore-errors.patch
Patch1:		ibus-kkc-optimize-update-property.patch
Patch2:		ibus-kkc-16th-candidate.patch
Patch3:		ibus-kkc-page-settings.patch
Patch4:		ibus-kkc-ignore-annotations.patch
Patch5:		ibus-kkc-optimize-update-property2.patch

BuildRequires:	vala
BuildRequires:	intltool
BuildRequires:	libkkc-devel >= 0.2.4
BuildRequires:	ibus-devel
BuildRequires:	gtk3-devel
BuildRequires:	desktop-file-utils
Requires:	ibus

%description
A Japanese Kana Kanji Input Method Engine for ibus.


%prep
%setup -q
%patch0 -p1 -b .ignore-errors
%patch1 -p1 -b .optimize-update-property
%patch2 -p1 -b .16th-candidate
%patch3 -p1 -b .page-settings
%patch4 -p1 -b .ignore-annotations
%patch5 -p1 -b .optimize-update-property2
rm src/*vala.stamp
# don't touch XKB layout under Fedora
sed -i 's!<layout>jp</layout>!<layout>default</layout>!' src/kkc.xml.in.in


%build
%configure
make %{?_smp_mflags}


%install
%make_install INSTALL="install -p"

desktop-file-validate %{buildroot}/%{_datadir}/applications/ibus-setup-kkc.desktop

%find_lang %{name}


%files -f %{name}.lang
%doc AUTHORS COPYING ChangeLog README
%{_datadir}/ibus-kkc
%{_libexecdir}/ibus-*-kkc
%{_datadir}/ibus/component/kkc.xml
%{_datadir}/applications/ibus-setup-kkc.desktop


%changelog
* Wed May 25 2016 Daiki Ueno <dueno@redhat.com> - 1.5.18-7
- add ibus-kkc-optimize-update-property2.patch (Closes: #1337888)

* Mon Mar 28 2016 Daiki Ueno <dueno@redhat.com> - 1.5.18-6
- add ibus-kkc-16th-candidate.patch (Closes: #1251882)
- add ibus-kkc-page-settings.patch (Closes: #1251891)
- add ibus-kkc-ignore-annotations.patch (Closes: #1251896)

* Mon Jun  9 2014 Daiki Ueno <dueno@redhat.com> - 1.5.18-5
- add ibus-kkc-optimize-update-property.patch (Closes: #1096888)

* Wed Feb 12 2014 Daiki Ueno <dueno@redhat.com> - 1.5.18-4
- add ibus-kkc-ignore-errors.patch (Closes: #1063564)

* Fri Jan 24 2014 Daniel Mach <dmach@redhat.com> - 1.5.18-3
- Mass rebuild 2014-01-24

* Fri Dec 27 2013 Daniel Mach <dmach@redhat.com> - 1.5.18-2
- Mass rebuild 2013-12-27

* Fri Sep 13 2013 Daiki Ueno <dueno@redhat.com> - 1.5.18-1
- new upstream release, with improved dictionary selection UI (Closes: #1007648)

* Tue Sep 10 2013 Daiki Ueno <dueno@redhat.com> - 1.5.17-1
- new upstream release, to avoid redundant LM loading (Closes: #1004722)

* Thu Jul 25 2013 Daiki Ueno <dueno@redhat.com> - 1.5.16-2
- remove buildroot cleanup
- validate .desktop file on %%install

* Thu Jul 11 2013 Daiki Ueno <dueno@redhat.com> - 1.5.16-1
- new upstream release (Closes: #980872)

* Fri Jul  5 2013 Daiki Ueno <dueno@redhat.com> - 1.5.15-1
- new upstream release

* Fri Jun  7 2013 Daiki Ueno <dueno@redhat.com> - 1.5.14-1
- new upstream release

* Wed May 15 2013 Daiki Ueno <dueno@redhat.com> - 1.5.13-1
- new upstream release

* Thu May  9 2013 Daiki Ueno <dueno@redhat.com> - 1.5.12-1
- new upstream release

* Thu May  2 2013 Daiki Ueno <dueno@redhat.com> - 1.5.11-2
- specify IBus version when configure

* Wed May  1 2013 Daiki Ueno <dueno@redhat.com> - 1.5.11-1
- new upstream release

* Tue Mar 19 2013 Daiki Ueno <dueno@redhat.com> - 1.5.10-1
- new upstream release

* Tue Mar 12 2013 Daiki Ueno <dueno@redhat.com> - 1.5.9-1
- new upstream release (Closes: #911495)

* Fri Feb 22 2013 Daiki Ueno <dueno@redhat.com> - 1.5.7-1
- new upstream release
- don't touch XKB layout (#910959)

* Mon Feb 11 2013 Daiki Ueno <dueno@redhat.com> - 1.5.6-1
- new upstream release
- change the license to GPLv2+

* Tue Feb  5 2013 Daiki Ueno <dueno@redhat.com> - 1.5.5-1
- new upstream release
- re-add README to %%doc

* Mon Feb  4 2013 Daiki Ueno <dueno@redhat.com> - 1.5.4-1
- new upstream release
- change the license to GPLv3+
- remove empty README file from %%doc

* Thu Jan 31 2013 Daiki Ueno <dueno@redhat.com> - 1.5.3-1
- new upstream release

* Thu Jan 24 2013 Daiki Ueno <dueno@redhat.com> - 1.5.0-1
- initial packaging

