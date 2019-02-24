#################################################
#penWrt Makefile for HelloWorld program
# Most of the variables used here are defined in
# the include directives below. We just need to
# specify a basic description of the package,
# where to build our program, where to find
# the source files, and where to install the
# compiled program on the router.
#
# Be very careful of spacing in this file.
# Indents should be tabs, not spaces, and
# there should be no trailing whitespace in
# lines that are not commented.
# 
##############################################
include $(TOPDIR)/rules.mk
# Name and release number of this package
PKG_NAME:=meshclient
PKG_RELEASE:=1


PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)


include $(INCLUDE_DIR)/package.mk

define Package/meshclient
    SECTION:=utils
    CATEGORY:=Utilities
    TITLE:=meshclient -- MRMC mesh client
endef


# Uncomment portion below for Kamikaze and delete DESCRIPTION variable above
define Package/meshclient/description
    This is the MRMC WMN's client.
endef


define Build/Prepare
    mkdir -p $(PKG_BUILD_DIR)
    $(CP) ./src/* $(PKG_BUILD_DIR)/
endef


define Package/meshclient/install
    $(INSTALL_DIR) $(1)/bin
    $(INSTALL_BIN) $(PKG_BUILD_DIR)/meshclient $(1)/bin/
endef


$(eval $(call BuildPackage,meshclient))
