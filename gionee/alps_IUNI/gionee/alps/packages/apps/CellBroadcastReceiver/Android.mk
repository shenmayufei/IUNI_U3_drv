ifneq ("$(APK_DEFAULT_CELLBROADCASTRECEIVER_SUPPORT)", "no")

# Copyright 2011 The Android Open Source Project

LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE_TAGS := optional

LOCAL_SRC_FILES := $(call all-java-files-under, src)
LOCAL_JAVA_LIBRARIES := telephony-common

LOCAL_PACKAGE_NAME := CellBroadcastReceiver
LOCAL_CERTIFICATE := platform

include $(BUILD_PACKAGE)

# This finds and builds the test apk as well, so a single make does both.
include $(call all-makefiles-under,$(LOCAL_PATH))

endif
