
LOCAL_PATH:= $(call my-dir)

ifneq ("$(APK_DEFAULT_BLUETOOTH_SUPPORT)", "no")

include $(CLEAR_VARS)

LOCAL_MODULE_TAGS := optional

LOCAL_SRC_FILES := \
        $(call all-java-files-under, src)

LOCAL_PACKAGE_NAME := Bluetooth
LOCAL_CERTIFICATE := platform

LOCAL_JNI_SHARED_LIBRARIES := libbluetooth_jni
LOCAL_JAVA_LIBRARIES := javax.obex telephony-common mms-common
LOCAL_STATIC_JAVA_LIBRARIES := com.android.vcard
LOCAL_STATIC_JAVA_LIBRARIES += com.android.emailcommon

LOCAL_REQUIRED_MODULES := libbluetooth_jni bluetooth.default

LOCAL_PROGUARD_ENABLED := disabled

include $(BUILD_PACKAGE)

endif
include $(call all-makefiles-under,$(LOCAL_PATH))
