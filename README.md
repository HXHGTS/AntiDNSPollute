## AntiDNSPollute（DNS防污染）

本地Windows环境下搭建DNS服务器，避免无良运营商进行dns投毒，并可选支持Adblock Plus广告拦截功能，也可仅用于解析出准确ip！

[下载地址（64位）](https://lanzous.com/icmfili)

[AdGuardHome下载地址（64位）](https://static.adguard.com/adguardhome/release/AdGuardHome_Windows_amd64.zip)

[下载地址（32位）](https://lanzous.com/icmfikh)

[AdGuardHome下载地址（32位）](https://static.adguard.com/adguardhome/release/AdGuardHome_Windows_386.zip)


### 使用说明

DNS防污染软件模式2基于开源软件AdGuardHome二次编程，便于直接在本地一键部署，因此需要AdGuardHome引擎才能正常运行！！！

使用时，请将zip文件解压后，把AdGuardHome.exe与本软件放在同一目录下！

本地DNS地址： 127.0.0.1 （ipv4）或 ::1 （ipv6），端口为标准的53端口，支持局域网内DNS解析结果分享

在本软件以模式2运行时，软件默认将无线网卡与有线网卡的dns设置为127.0.0.1与::1，若还需要在其他网卡上使用，请自行设置其DNS为127.0.0.1与::1

同一局域网内的设备可将DNS服务器直接指向此设备的内网ip，如192.168.1.x，即可使用无污染DNS，无需另外设置！

WEB登陆默认用户名与密码均为root，可根据自行需要修改，若不慎忘记，可使用模式5重置，相关设置也将被覆盖！

更新时，可以在软件关闭的情况下将文件直接覆盖即可！
