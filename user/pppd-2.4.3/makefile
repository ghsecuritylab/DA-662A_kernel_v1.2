# History:
# Date		Author			Comment
# 06-12-2009	Jared Wu.		install at BERoot or LERoot
# 12-29-2011	Aeluin Chen.	do not install at INSTALL_ROOT, instead of TC_INSTALL_PREFIX
#
# compile: 
#	make user/pppd-2.4.3_only


all: $(TC_INSTALL_PREFIX)/sbin/pppd 

$(TC_INSTALL_PREFIX)/sbin/pppd: build_$(CONFIGURE_TARGET)-linux/pppd
	[ -d $(ROMFSDIR)/share/man/man8 ] || mkdir -p $(ROMFSDIR)/share/man/man8
	unset LDFLAGS CFLAGS CPPFLAGS CXXFLAGS && \
	make DESTDIR=$(TC_INSTALL_PREFIX) -C build_$(CONFIGURE_TARGET)-linux -f Makefile install

build_$(CONFIGURE_TARGET)-linux/pppd: build_$(CONFIGURE_TARGET)-linux/Makefile
	unset LDFLAGS CFLAGS CPPFLAGS CXXFLAGS && \
	make -C build_$(CONFIGURE_TARGET)-linux/chat -f Makefile CC=$(CROSS)gcc CXX=$(CROSS)g++ LD=$(CROSS)ld CPP=$(CROSS)cpp STRIP=$(CROSS)strip;
	unset LDFLAGS CFLAGS CPPFLAGS CXXFLAGS && \
	make -C build_$(CONFIGURE_TARGET)-linux/pppd/plugins -f Makefile CC=$(CROSS)gcc CXX=$(CROSS)g++ LD=$(CROSS)ld CPP=$(CROSS)cpp STRIP=$(CROSS)strip;
	unset LDFLAGS CFLAGS CPPFLAGS CXXFLAGS && \
	make -C build_$(CONFIGURE_TARGET)-linux/pppd -f Makefile CC=$(CROSS)gcc CXX=$(CROSS)g++ LD=$(CROSS)ld CPP=$(CROSS)cpp STRIP=$(CROSS)strip;
	unset LDFLAGS CFLAGS CPPFLAGS CXXFLAGS && \
	make -C build_$(CONFIGURE_TARGET)-linux/pppstats -f Makefile CC=$(CROSS)gcc CXX=$(CROSS)g++ LD=$(CROSS)ld CPP=$(CROSS)cpp STRIP=$(CROSS)strip;
	unset LDFLAGS CFLAGS CPPFLAGS CXXFLAGS && \
	make -C build_$(CONFIGURE_TARGET)-linux/pppdump -f Makefile CC=$(CROSS)gcc CXX=$(CROSS)g++ LD=$(CROSS)ld CPP=$(CROSS)cpp STRIP=$(CROSS)strip;

build_$(CONFIGURE_TARGET)-linux/Makefile: makefile
	tar xzvf ppp-2.4.3.tar.gz
	mv ppp-2.4.3 build_$(CONFIGURE_TARGET)-linux
	( cd build_$(CONFIGURE_TARGET)-linux; \
	./configure; \
	sed -ie 's/-s//g' chat/Makefile;\
	sed -ie 's/$$(INSTALL) -s/$$(INSTALL)/g' pppd/Makefile;\
	sed -ie 's/$$(INSTALL) -s/$$(INSTALL)/g' pppstats/Makefile;\
	sed -ie 's/$$(INSTALL) -s/$$(INSTALL)/g' pppdump/Makefile;\
	sed -ie 's/$$(INSTALL) -s/$$(INSTALL)/g' pppd/plugins/rp-pppoe/Makefile;\
	sed -ie 's/$$(INSTALL) -s/$$(INSTALL)/g' pppd/plugins/radius/Makefile;\
	)
	
romfs: #$(TC_INSTALL_PREFIX)/sbin/pppd 
	$(ROMFSINST) $(TC_INSTALL_PREFIX)/sbin/pppd /sbin/pppd
	$(STRIP) -s $(ROMFSDIR)/sbin/pppd
	$(ROMFSINST) $(TC_INSTALL_PREFIX)/sbin/chat /usr/sbin/chat
	$(STRIP) -s $(ROMFSDIR)/usr/sbin/chat
	$(ROMFSINST) $(TC_INSTALL_PREFIX)/lib/pppd/2.4.3/rp-pppoe.so /lib/rp-pppoe.so
	#$(STRIP) -s $(ROMFSDIR)/lib/rp-pppoe.so

package:
	echo "Nothing to do"

clean distclean:
	rm -rf build_$(CONFIGURE_TARGET)-linux

