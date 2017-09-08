#!/bin/bash

echo "# begin build properties"
echo "# autogenerated by buildinfo.sh"

echo "ro.build.id=$BUILD_ID"
#echo "ro.build.display.id=$BUILD_DISPLAY_ID"
echo "ro.build.version.incremental=$BUILD_NUMBER"
echo "ro.build.version.sdk=$PLATFORM_SDK_VERSION"
echo "ro.build.version.codename=$PLATFORM_VERSION_CODENAME"
echo "ro.build.version.release=$PLATFORM_VERSION"
echo "ro.build.date=`date`"
echo "ro.build.date.utc=`date +%s`"
echo "ro.build.type=$TARGET_BUILD_TYPE"
echo "ro.build.user=$USER"
echo "ro.build.host=`hostname`"
echo "ro.build.tags=$BUILD_VERSION_TAGS"
#echo "ro.product.model=$PRODUCT_MODEL"
#echo "ro.product.brand=$PRODUCT_BRAND"
#echo "ro.product.name=$PRODUCT_NAME"
#echo "ro.product.device=$TARGET_DEVICE"
echo "ro.product.board=$TARGET_BOOTLOADER_BOARD_NAME"
echo "ro.product.cpu.abi=$TARGET_CPU_ABI"
if [ -n "$TARGET_CPU_ABI2" ] ; then
  echo "ro.product.cpu.abi2=$TARGET_CPU_ABI2"
fi
#echo "ro.product.manufacturer=$PRODUCT_MANUFACTURER"
if [ -n "$PRODUCT_DEFAULT_LANGUAGE" ] ; then
  echo "ro.product.locale.language=$PRODUCT_DEFAULT_LANGUAGE"
fi
if [ -n "$PRODUCT_DEFAULT_REGION" ] ; then
  echo "ro.product.locale.region=$PRODUCT_DEFAULT_REGION"
fi
echo "ro.wifi.channels=$PRODUCT_DEFAULT_WIFI_CHANNELS"
echo "ro.board.platform=$TARGET_BOARD_PLATFORM"

echo "# ro.build.product is obsolete; use ro.product.device"
echo "ro.build.product=$TARGET_DEVICE"

echo "# Do not try to parse ro.build.description or .fingerprint"
echo "ro.build.description=$PRIVATE_BUILD_DESC"
echo "ro.build.fingerprint=$BUILD_FINGERPRINT"
echo "ro.build.characteristics=$TARGET_AAPT_CHARACTERISTICS"


###add by IUNI wangyongliang
echo "ro.gn.gemini.support=no"
echo "ro.internal.storage=/storage/emulated/0"
echo "ro.external.storage=/storage/usbotg"
echo "ro.gn.extvernumber=IUNI-Alpha-1.0"

get_time() {
    time=`date -Iseconds`
        time=${time%+0800}
    time=${time//-/}
    time=${time//:/}
    time=${time//T/}
    time=${time:0:(${#time}-2)}
    echo $time
}

version=$(get_time)

factory=`cat ~/U3m/trunk/gionee/alps_IUNI/gionee/project/NBL8905A/build/tools/factoryver`
let factory+=1
echo $factory>~/U3m/trunk/gionee/alps_IUNI/gionee/project/NBL8905A/build/tools/factoryver

echo "ro.gn.iuniznvernumber=IUNI-U3m-AlphaV1.0-$version"
echo "ro.gn.gnznvernumber=NBL8905A01_A_T"$factory
echo IUNI-U3m-AlphaV1.0-$version>ver
echo "ro.iuni.internalmemory=32"

####Ringtone
echo "ro.config.ringtone=iuniTune.ogg"
echo "ro.config.notification_sound=Blip.ogg"
echo "ro.gn.gnromvernumber=IUNI ROM4.4"
echo "ro.gn.gnotaupdate.support=yes"
echo "ro.gn.usb.ui.support=yes"
echo "persist.sys.aurora.debug=no"

echo "persist.iuni.sim.type=unknown"

echo "ro.sf.lcd_density=480"

echo "persist.sys.aurora.device.sn=iuni"
echo "persist.sys.logkit.ctrlcode=1"
echo "persist.sys.aurora.debug=yes"
echo "ro.aurora.reject.support=yes"
echo "persist.sys.country=CN"
echo "persist.sys.language=zh"
###end add by IUNI wangyongliang


echo "# end build properties"