## AntiDNSPollute（DNS防污染）

本地Windows环境下搭建DNS服务器，避免无良运营商进行dns投毒，并可选支持Adblock Plus或AdGuard广告拦截功能，也可直接关闭去广告插件，仅用于解析出准确ip！

[下载地址（单文件64位，需要配合AdGuardHome使用）](https://wwa.lanzous.com/iautrf67vpe) [AdGuardHome下载地址（64位）](https://static.adguard.com/adguardhome/release/AdGuardHome_Windows_amd64.zip)

[下载地址（单文件32位，需要配合AdGuardHome使用）](https://wwa.lanzous.com/ilCSVf67w6b) [AdGuardHome下载地址（32位）](https://static.adguard.com/adguardhome/release/AdGuardHome_Windows_386.zip)

### 使用说明

本地DNS模式基于开源软件AdGuardHome二次编程，便于直接在本地一键部署，因此需要AdGuardHome引擎才能正常运行！！！

下载并解压zip包中的AdGuardHome.exe，放到与AntiDNSPollute.exe同一目录下，单击AntiDNSPollute.exe即可运行！

注意：由于AdGuardHome机制，请给予管理员权限！

本地DNS地址： 127.0.0.1 （ipv4）或 ::1 （ipv6），端口为标准的53端口，支持局域网内DNS解析结果分享

在本地DNS模式运行时，软件默认将无线网卡与有线网卡的dns设置为127.0.0.1与::1，若还需要在其他网卡上使用，请自行设置其DNS为127.0.0.1与::1

同一局域网内的设备可将DNS服务器直接指向此设备的内网ip，如192.168.1.x，即可使用无污染DNS，无需另外设置！

WEB登陆默认用户名与密码均为root，可根据自行需要修改，若不慎忘记，可使用模式5重置，相关设置也将被覆盖！

更新时，可以在软件关闭的情况下将文件直接覆盖即可！建议每次更新DNS防污染程序后使用模式5恢复一次默认设置，以便应用更新功能特性！

##### 提示：exe文件更新很慢，建议自己下载[源代码](https://github.com/HXHGTS/AntiDNSPollute/archive/master.zip)使用Visual Studio 2019编译.Sln文件即可获得最新版exe！

### 使用本地DNS模式时请务必注意！！！

使用本地DNS模式期间请不要关闭本窗口及其弹出窗口，后台最小化即可！！！

如需停止DNS解析请务必在本窗口中按x加enter键恢复默认DNS设置，否则会导致无法上网！！！

如果不小心关闭本软件，可以重新打开本软件恢复默认DNS！！！

### 更新日志（2020.7.31）

1.删除配置全局类VPN一键国内外分流功能，增加安全性，需要此功能请使用SmartDNS智能国内外分流；

2.支持自定义模式1的临时hosts文件，自动备份系统hosts；

### 更新日志（2020.5.27）

1.新增一键配置全局类VPN一键国内外分流+本地DNS的功能，简化操作；

2.优化部分可能略显繁琐的操作；

3.重传DelRouteRules.txt，上次上传时由于空格可能导致路由表恢复过程失败，现已修复；

### 更新日志（2020.5.23）

1.新增自动修改Windows路由表特性，便于直接接管全局类VPN的DNS国内外解析功能，需要cmroute.dll插件；

2.DNS直接使用宽带带宽解析，避免给服务器增加负载；

3.UI小优化；

### 更新日志（2020.5.17）

1.去除原本存在部分污染的模式1，仅保留无污染的模式2；

2.支持最新版AdGuardHome特性；

3.对使用Cloudflare CDN加速的workers.dev网站进行解析优化；

4.增加上游ipv6环境支持；

5.OpenDNS开始完全使用加密解析，非标准端口解析仅用作解析上游，不再直接解析结果；

#### 开发者邮箱：

[admin@hxhgts.cf](mailto:admin@hxhgts.cf)
