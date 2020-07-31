#include<stdio.h>
#include<stdlib.h>
int Boot();
int UserInterface();
int RunLocalDNSServer();
int NetFixTool();
int ConfigEditor();
int ConfigToDefault();
int NSTool();
int Help();
int FixHosts();
int Config_gen();
int Reset();


int mode,DNSSet,fixmode,DNSServer,ADSwitch,Geo_Mode;
FILE* yaml,*AdGuardHome,*SystemHosts,*bak,*ADFilter,*dll;
char ADFilterRules[536],domain[50],NSCommand[72],Adapter[60], WhiteList[2159],Command[120];
char TopDNS[287] = "  - 208.67.222.222:5353\n  - 208.67.220.220:5353\n  - 208.67.222.220:5353\n  - 208.67.220.222:5353\n";//定义上游DNS服务器，直接去除污染
char Rewrite[296]="  - domain: '*.workers.dev'\n    answer: 1.0.0.1\n  - domain: '*.cloudflare.com'\n    answer: 1.0.0.1\n  - domain: '*.s3.amazonaws.com'\n    answer: 's3.amazonaws.com'\n  - domain: '*.githubusercontent.com'\n    answer: 151.101.76.133\n  - domain: '*.pdx01.abs.hls.ttvnw.net'\n    answer: 35.164.243.189\n";
char Hosts[6]="- \"\"\n";
char ABP_Filter[529]="\n- enabled: true\n  url: https://easylist-downloads.adblockplus.org/abp-filters-anti-cv.txt\n  name: ABP filters\n  id: 1588581704\n- enabled: true\n  url: https://easylist-downloads.adblockplus.org/easyprivacy.txt\n  name: EasyPrivacy\n  id: 1588581706\n- enabled: true\n  url: https://easylist-downloads.adblockplus.org/fanboy-social.txt\n  name: Fanboy's Social Blocking List\n  id: 1588581707\n- enabled: true\n  url: https://easylist-downloads.adblockplus.org/easylistchina+easylist.txt\n  name: EasyList China+EasyList\n  id: 1588581708\n";//ABP数据库
char AdGuard_Filter[533]="\n- enabled: true\n  url: https://filters.adtidy.org/extension/chromium/filters/2.txt\n  name: AdGuard Base filter\n  id: 1589448814\n- enabled: true\n  url: https://filters.adtidy.org/extension/chromium/filters/3.txt\n  name: AdGuard Tracking Protection filter\n  id: 1589448815\n- enabled: true\n  url: https://filters.adtidy.org/extension/chromium/filters/4.txt\n  name: AdGuard Social Media filter\n  id: 1589448816\n- enabled: true\n  url: https://easylist-downloads.adblockplus.org/easylistchina.txt\n  name: EasyList China\n  id: 1589448817\n";//AdGuard数据库

int UserInterface() {
	printf("请选择DNS服务器运行方式：\n\n1.运行本地DNS\n\n2.全局类VPN软件分流\n\n3.自定义DNS解析Hosts(仅模式1开启时有效)\n\n4.重置DNS（运行本地DNS时未正常退出，可用此选项恢复上网功能）\n\n5.自定义DNS配置文件（用于添加自定义上游）\n\n6.重置配置文件（自定义失败时可用于恢复默认，用户名密码也将被重置）\n\n7.无污染DNS解析结果获取（不修改本机DNS，仅输出结果）\n\n8.重置系统Hosts文件\n\n9.在线帮助\n\n0.退出\n\n请输入：");
	scanf("%d", &mode);
	system("cls");
	return 0;
}

int main() {
MainMenu:system("cls");
	UserInterface();
	if (mode == 1) {
		if (Boot() != 0) {
			printf("未在软件目录中发现AdGuardHome引擎，请在官网下载后放置在本软件同一目录下！\n\n");
			system("pause");
			goto MainMenu;
		}
		system("cls");
		RunLocalDNSServer();
		goto MainMenu;
	}
	else if (mode == 2) {
		Boot();
		system("cls");
		printf("请在弹出窗口中修改，记得保存. . .\n");
		system("notepad hosts");
		goto MainMenu;
	}
	else if (mode == 4) {
		NetFixTool();
		goto MainMenu;
	}
	else if (mode == 5) {
		Boot();
		if (Boot() != 0) {
			printf("未在软件目录中发现AdGuardHome引擎，请在官网下载后放置在本软件同一目录下！\n\n");
			system("pause");
			goto MainMenu;
		}
		system("cls");
		ConfigEditor();
		goto MainMenu;
}
	else if (mode == 6) {
		Boot();
		if (Boot() != 0) {
			printf("未在软件目录中发现AdGuardHome引擎，请在官网下载后放置在本软件同一目录下！\n\n");
			system("pause");
			goto MainMenu;
		}
		system("cls");
		ConfigToDefault();
		goto MainMenu;
}
	else if (mode == 7) {
		NSTool();
		goto MainMenu;
	}
	else if (mode == 8) {
		FixHosts();
		goto MainMenu;
	}
	else if (mode == 9) {
		Help();
		goto MainMenu;
}
	else if (mode == 0) {
		exit(0);
	}
	else {
		goto MainMenu;
	}
	return 0;
}

int Config_gen() {
	printf("注意：节点1、8为国内节点，解析速度更快，但可能会留下解析日志，使用请注意！\n\n");
	printf("指定上游DNS服务器区域：\n\n1.Cisco OpenDNS（中国香港）（加密解析，服务器在国外，安全性高）\n\n2.GoogleDNS（美国中部）（加密解析，服务器在国外，安全性高）\n\n3.AdGuardDNS（俄罗斯）（加密解析，服务器在国外，安全性高）\n\n4.IBM Quad9（美国中部）（加密解析，服务器在国外，安全性高）\n\n5.CloudflareDNS（中国香港）（加密解析，服务器在国外，无日志记录，安全性极高）\n\n6.清华大学TUNA666（教育网节点，非加密，解析速度快）\n\n请输入：");
	scanf("%d", &DNSServer);
	system("cls");
	printf("广告拦截模式：\n\n1.开启Adblock Plus拦截\n\n2.开启AdGuard拦截\n\n3.不拦截\n\n请输入：");
	scanf("%d", &ADSwitch);
	system("cls");
	if (DNSServer ==8) {
		Geo_Mode = 2;
	}
	else {
		printf("启用国内外分流：\n\n1.启用分流\n\n2.全局模式\n\n请输入：");
		scanf("%d", &Geo_Mode);
	}
		yaml = fopen("index.yaml", "w");
		if (ADSwitch == 1) {
			sprintf(ADFilterRules, "%s",ABP_Filter);

		}
		 else if (ADSwitch == 2) {
			sprintf(ADFilterRules, "%s", AdGuard_Filter);
		}
		else {
			sprintf(ADFilterRules, "[]\n");
		}
		if (Geo_Mode == 2) {
			sprintf(WhiteList, "");//全局模式
		}
		else {
			sprintf(WhiteList,"  - '[/netease.com/]119.29.29.29'\n  - '[/126.net/]119.29.29.29'\n  - '[/icourse163.org/]119.29.29.29'\n  - '[/yeah.net/]119.29.29.29'\n  - '[/126.com/]119.29.29.29'\n  - '[/163.com/]119.29.29.29'\n  - '[/google.cn/]119.29.29.29'\n  - '[/baidu.com/]119.29.29.29'\n  - '[/baidupcs.com/]119.29.29.29'\n  - '[/bdstatic.com/]119.29.29.29'\n  - '[/bilibili.com/]119.29.29.29'\n  - '[/bilivideo.com/]119.29.29.29'\n  - '[/akamaized.net/]119.29.29.29'\n  - '[/hdslb.com/]119.29.29.29'\n  - '[/qq.com/]119.29.29.29'\n  - '[/douyu.com/]119.29.29.29'\n  - '[/huya.com/]119.29.29.29'\n  - '[/aliyun.com/]119.29.29.29'\n  - '[/alicdn.com/]119.29.29.29'\n  - '[/alipay.com/]119.29.29.29'\n  - '[/taobao.com/]119.29.29.29'\n  - '[/tmall.com/]119.29.29.29'\n  - '[/jd.com/]119.29.29.29'\n  - '[/zxxk.com/]119.29.29.29'\n  - '[/cnzz.com/]119.29.29.29'\n  - '[/chaoxing.com/]119.29.29.29'\n  - '[/snnu.edu.cn/]119.29.29.29'\n  - '[/ipip.net/]119.29.29.29'\n  - '[/7moor.com/]119.29.29.29'\n  - '[/t.cn/]119.29.29.29'\n  - '[/chinaz.com/]119.29.29.29'\n  - '[/uzer.me/]119.29.29.29'\n  - '[/lanzou.com/]119.29.29.29'\n  - '[/lanzous.com/]119.29.29.29'\n  - '[/baidupan.com/]119.29.29.29'\n  - '[/v.smtcdns.com/]119.29.29.29'\n  - '[/youku.com/]119.29.29.29'\n  - '[/ott.cibntv.net/]119.29.29.29'\n  - '[/zhihu.com/]119.29.29.29'\n  - '[/zhimg.com/]119.29.29.29'\n  - '[/cnki.net/]119.29.29.29'\n  - '[/iqiyi.com/]119.29.29.29'\n  - '[/qy.net/]119.29.29.29'\n  - '[/iqiyipic.com/]119.29.29.29'\n  - '[/acfun.cn/]119.29.29.29'\n  - '[/aixifan.com/]119.29.29.29'\n  - '[/yximgs.com/]119.29.29.29'\n  - '[/ksurl.cn/]119.29.29.29'\n  - '[/139.com/]119.29.29.29'\n  - '[/10086.cn/]119.29.29.29'\n  - '[/189.cn/]119.29.29.29'\n  - '[/knet.cn/]119.29.29.29'\n  - '[/10010.cn/]119.29.29.29'\n  - '[/10010.com/]119.29.29.29'\n  - '[/weibo.com/]119.29.29.29'\n  - '[/sina.com.cn/]119.29.29.29'\n  - '[/sohu.com/]119.29.29.29'\n  - '[/cctv.cn/]119.29.29.29'\n  - '[/nn.com/]119.29.29.29'\n  - '[/xunyou.com/]119.29.29.29'\n  - '[/leigod.com/]119.29.29.29'\n  - '[/gitee.io/]119.29.29.29'\n  - '[/eccdnx.com/]119.29.29.29'\n  - '[/iplaysoft.com/]119.29.29.29'\n  - '[/jianshu.com/]119.29.29.29'\n  - '[/edu.cn/]119.29.29.29'\n  - '[/gov.cn/]119.29.29.29'\n");//常用国内域名分流
		}
		if (DNSServer == 1)fprintf(yaml, "bind_host: 0.0.0.0\nbind_port: 80\nusers:\n- name: root\n  password: $2a$10$mdmUKhmmhuDQO8GHlU.8xOWzwG6Fy.5o5YUCUWYg2DkyfgYRsM0hy\nhttp_proxy: ""\nlanguage: ""\nrlimit_nofile: 0\nweb_session_ttl: 720\ndns:\n  bind_host: 0.0.0.0\n  port: 53\n  statistics_interval: 1\n  querylog_enabled: true\n  querylog_interval: 90\n  querylog_size_memory: 1000\n  anonymize_client_ip: false\n  protection_enabled: true\n  blocking_mode: default\n  blocking_ipv4: \"\"\n  blocking_ipv6: \"\"\n  blocked_response_ttl: 10\n  ratelimit: 0\n  ratelimit_whitelist: []\n  refuse_any: true\n  bootstrap_dns:\n%s  all_servers: true\n  fastest_addr: false\n  edns_client_subnet: true\n  enable_dnssec: true\n  aaaa_disabled: false\n  allowed_clients: []\n  disallowed_clients: []\n  blocked_hosts: []\n  parental_block_host: family-block.dns.adguard.com\n  safebrowsing_block_host: standard-block.dns.adguard.com\n  cache_size: 0\n  cache_ttl_min: 0\n  cache_ttl_max: 0\n  upstream_dns:\n%s%s  filtering_enabled: true\n  filters_update_interval: 24\n  parental_enabled: false\n  safesearch_enabled: false\n  safebrowsing_enabled: false\n  safebrowsing_cache_size: 1048576\n  safesearch_cache_size: 1048576\n  parental_cache_size: 1048576\n  cache_time: 30\n  rewrites: \n%s  blocked_services: []\ntls:\n  enabled: false\n  server_name: \"\"\n  force_https: false\n  port_https: 443\n  port_dns_over_tls: 853\n  allow_unencrypted_doh: false\n  strict_sni_check: false\n  certificate_chain: \"\"\n  private_key: \"\"\n  certificate_path: \"\"\n  private_key_path: \"\"\nfilters: %swhitelist_filters: []\nuser_rules:\n%sdhcp:\n  enabled: false\n  interface_name: \"\"\n  gateway_ip: \"\"\n  subnet_mask: \"\"\n  range_start: \"\"\n  range_end: \"\"\n  lease_duration: 86400\n  icmp_timeout_msec: 1000\nclients: []\nlog_file: \"\"\nverbose: false\nschema_version: 6\n", TopDNS,  "  - https://doh.opendns.com/dns-query\n", WhiteList, Rewrite, ADFilterRules, Hosts);
		else if (DNSServer == 2)fprintf(yaml, "bind_host: 0.0.0.0\nbind_port: 80\nusers:\n- name: root\n  password: $2a$10$mdmUKhmmhuDQO8GHlU.8xOWzwG6Fy.5o5YUCUWYg2DkyfgYRsM0hy\nhttp_proxy: ""\nlanguage: ""\nrlimit_nofile: 0\nweb_session_ttl: 720\ndns:\n  bind_host: 0.0.0.0\n  port: 53\n  statistics_interval: 1\n  querylog_enabled: true\n  querylog_interval: 90\n  querylog_size_memory: 1000\n  anonymize_client_ip: false\n  protection_enabled: true\n  blocking_mode: default\n  blocking_ipv4: \"\"\n  blocking_ipv6: \"\"\n  blocked_response_ttl: 10\n  ratelimit: 0\n  ratelimit_whitelist: []\n  refuse_any: true\n  bootstrap_dns:\n%s  all_servers: true\n  fastest_addr: false\n  edns_client_subnet: true\n  enable_dnssec: true\n  aaaa_disabled: false\n  allowed_clients: []\n  disallowed_clients: []\n  blocked_hosts: []\n  parental_block_host: family-block.dns.adguard.com\n  safebrowsing_block_host: standard-block.dns.adguard.com\n  cache_size: 0\n  cache_ttl_min: 0\n  cache_ttl_max: 0\n  upstream_dns:\n%s%s  filtering_enabled: true\n  filters_update_interval: 24\n  parental_enabled: false\n  safesearch_enabled: false\n  safebrowsing_enabled: false\n  safebrowsing_cache_size: 1048576\n  safesearch_cache_size: 1048576\n  parental_cache_size: 1048576\n  cache_time: 30\n  rewrites: \n%s  blocked_services: []\ntls:\n  enabled: false\n  server_name: \"\"\n  force_https: false\n  port_https: 443\n  port_dns_over_tls: 853\n  allow_unencrypted_doh: false\n  strict_sni_check: false\n  certificate_chain: \"\"\n  private_key: \"\"\n  certificate_path: \"\"\n  private_key_path: \"\"\nfilters: %swhitelist_filters: []\nuser_rules:\n%sdhcp:\n  enabled: false\n  interface_name: \"\"\n  gateway_ip: \"\"\n  subnet_mask: \"\"\n  range_start: \"\"\n  range_end: \"\"\n  lease_duration: 86400\n  icmp_timeout_msec: 1000\nclients: []\nlog_file: \"\"\nverbose: false\nschema_version: 6\n", TopDNS,  "  - tls://dns.google\n  - https://dns.google/dns-query\n", WhiteList, Rewrite, ADFilterRules, Hosts);
		else if (DNSServer == 3)fprintf(yaml, "bind_host: 0.0.0.0\nbind_port: 80\nusers:\n- name: root\n  password: $2a$10$mdmUKhmmhuDQO8GHlU.8xOWzwG6Fy.5o5YUCUWYg2DkyfgYRsM0hy\nhttp_proxy: ""\nlanguage: ""\nrlimit_nofile: 0\nweb_session_ttl: 720\ndns:\n  bind_host: 0.0.0.0\n  port: 53\n  statistics_interval: 1\n  querylog_enabled: true\n  querylog_interval: 90\n  querylog_size_memory: 1000\n  anonymize_client_ip: false\n  protection_enabled: true\n  blocking_mode: default\n  blocking_ipv4: \"\"\n  blocking_ipv6: \"\"\n  blocked_response_ttl: 10\n  ratelimit: 0\n  ratelimit_whitelist: []\n  refuse_any: true\n  bootstrap_dns:\n%s  all_servers: true\n  fastest_addr: false\n  edns_client_subnet: true\n  enable_dnssec: true\n  aaaa_disabled: false\n  allowed_clients: []\n  disallowed_clients: []\n  blocked_hosts: []\n  parental_block_host: family-block.dns.adguard.com\n  safebrowsing_block_host: standard-block.dns.adguard.com\n  cache_size: 0\n  cache_ttl_min: 0\n  cache_ttl_max: 0\n  upstream_dns:\n%s%s  filtering_enabled: true\n  filters_update_interval: 24\n  parental_enabled: false\n  safesearch_enabled: false\n  safebrowsing_enabled: false\n  safebrowsing_cache_size: 1048576\n  safesearch_cache_size: 1048576\n  parental_cache_size: 1048576\n  cache_time: 30\n  rewrites: \n%s  blocked_services: []\ntls:\n  enabled: false\n  server_name: \"\"\n  force_https: false\n  port_https: 443\n  port_dns_over_tls: 853\n  allow_unencrypted_doh: false\n  strict_sni_check: false\n  certificate_chain: \"\"\n  private_key: \"\"\n  certificate_path: \"\"\n  private_key_path: \"\"\nfilters: %swhitelist_filters: []\nuser_rules:\n%sdhcp:\n  enabled: false\n  interface_name: \"\"\n  gateway_ip: \"\"\n  subnet_mask: \"\"\n  range_start: \"\"\n  range_end: \"\"\n  lease_duration: 86400\n  icmp_timeout_msec: 1000\nclients: []\nlog_file: \"\"\nverbose: false\nschema_version: 6\n", TopDNS,  "  - tls://dns.adguard.com\n  - https://dns.adguard.com/dns-query\n", WhiteList, Rewrite, ADFilterRules, Hosts);
		else if (DNSServer == 4)fprintf(yaml, "bind_host: 0.0.0.0\nbind_port: 80\nusers:\n- name: root\n  password: $2a$10$mdmUKhmmhuDQO8GHlU.8xOWzwG6Fy.5o5YUCUWYg2DkyfgYRsM0hy\nhttp_proxy: ""\nlanguage: ""\nrlimit_nofile: 0\nweb_session_ttl: 720\ndns:\n  bind_host: 0.0.0.0\n  port: 53\n  statistics_interval: 1\n  querylog_enabled: true\n  querylog_interval: 90\n  querylog_size_memory: 1000\n  anonymize_client_ip: false\n  protection_enabled: true\n  blocking_mode: default\n  blocking_ipv4: \"\"\n  blocking_ipv6: \"\"\n  blocked_response_ttl: 10\n  ratelimit: 0\n  ratelimit_whitelist: []\n  refuse_any: true\n  bootstrap_dns:\n%s  all_servers: true\n  fastest_addr: false\n  edns_client_subnet: true\n  enable_dnssec: true\n  aaaa_disabled: false\n  allowed_clients: []\n  disallowed_clients: []\n  blocked_hosts: []\n  parental_block_host: family-block.dns.adguard.com\n  safebrowsing_block_host: standard-block.dns.adguard.com\n  cache_size: 0\n  cache_ttl_min: 0\n  cache_ttl_max: 0\n  upstream_dns:\n%s%s  filtering_enabled: true\n  filters_update_interval: 24\n  parental_enabled: false\n  safesearch_enabled: false\n  safebrowsing_enabled: false\n  safebrowsing_cache_size: 1048576\n  safesearch_cache_size: 1048576\n  parental_cache_size: 1048576\n  cache_time: 30\n  rewrites: \n%s  blocked_services: []\ntls:\n  enabled: false\n  server_name: \"\"\n  force_https: false\n  port_https: 443\n  port_dns_over_tls: 853\n  allow_unencrypted_doh: false\n  strict_sni_check: false\n  certificate_chain: \"\"\n  private_key: \"\"\n  certificate_path: \"\"\n  private_key_path: \"\"\nfilters: %swhitelist_filters: []\nuser_rules:\n%sdhcp:\n  enabled: false\n  interface_name: \"\"\n  gateway_ip: \"\"\n  subnet_mask: \"\"\n  range_start: \"\"\n  range_end: \"\"\n  lease_duration: 86400\n  icmp_timeout_msec: 1000\nclients: []\nlog_file: \"\"\nverbose: false\nschema_version: 6\n", TopDNS,  "  - https://dns.quad9.net/dns-query\n  - tls://dns.quad9.net\n", WhiteList, Rewrite, ADFilterRules, Hosts);
		else if (DNSServer == 5)fprintf(yaml, "bind_host: 0.0.0.0\nbind_port: 80\nusers:\n- name: root\n  password: $2a$10$mdmUKhmmhuDQO8GHlU.8xOWzwG6Fy.5o5YUCUWYg2DkyfgYRsM0hy\nhttp_proxy: ""\nlanguage: ""\nrlimit_nofile: 0\nweb_session_ttl: 720\ndns:\n  bind_host: 0.0.0.0\n  port: 53\n  statistics_interval: 1\n  querylog_enabled: true\n  querylog_interval: 90\n  querylog_size_memory: 1000\n  anonymize_client_ip: false\n  protection_enabled: true\n  blocking_mode: default\n  blocking_ipv4: \"\"\n  blocking_ipv6: \"\"\n  blocked_response_ttl: 10\n  ratelimit: 0\n  ratelimit_whitelist: []\n  refuse_any: true\n  bootstrap_dns:\n%s  all_servers: true\n  fastest_addr: false\n  edns_client_subnet: true\n  enable_dnssec: true\n  aaaa_disabled: false\n  allowed_clients: []\n  disallowed_clients: []\n  blocked_hosts: []\n  parental_block_host: family-block.dns.adguard.com\n  safebrowsing_block_host: standard-block.dns.adguard.com\n  cache_size: 0\n  cache_ttl_min: 0\n  cache_ttl_max: 0\n  upstream_dns:\n%s%s  filtering_enabled: true\n  filters_update_interval: 24\n  parental_enabled: false\n  safesearch_enabled: false\n  safebrowsing_enabled: false\n  safebrowsing_cache_size: 1048576\n  safesearch_cache_size: 1048576\n  parental_cache_size: 1048576\n  cache_time: 30\n  rewrites: \n%s  blocked_services: []\ntls:\n  enabled: false\n  server_name: \"\"\n  force_https: false\n  port_https: 443\n  port_dns_over_tls: 853\n  allow_unencrypted_doh: false\n  strict_sni_check: false\n  certificate_chain: \"\"\n  private_key: \"\"\n  certificate_path: \"\"\n  private_key_path: \"\"\nfilters: %swhitelist_filters: []\nuser_rules:\n%sdhcp:\n  enabled: false\n  interface_name: \"\"\n  gateway_ip: \"\"\n  subnet_mask: \"\"\n  range_start: \"\"\n  range_end: \"\"\n  lease_duration: 86400\n  icmp_timeout_msec: 1000\nclients: []\nlog_file: \"\"\nverbose: false\nschema_version: 6\n", TopDNS,  "  - tls://1dot1dot1dot1.cloudflare-dns.com\n  - https://dns.cloudflare.com/dns-query\n", WhiteList, Rewrite, ADFilterRules, Hosts);
		else fprintf(yaml, "bind_host: 0.0.0.0\nbind_port: 80\nusers:\n- name: root\n  password: $2a$10$mdmUKhmmhuDQO8GHlU.8xOWzwG6Fy.5o5YUCUWYg2DkyfgYRsM0hy\nhttp_proxy: ""\nlanguage: ""\nrlimit_nofile: 0\nweb_session_ttl: 720\ndns:\n  bind_host: 0.0.0.0\n  port: 53\n  statistics_interval: 1\n  querylog_enabled: true\n  querylog_interval: 90\n  querylog_size_memory: 1000\n  anonymize_client_ip: false\n  protection_enabled: true\n  blocking_mode: default\n  blocking_ipv4: \"\"\n  blocking_ipv6: \"\"\n  blocked_response_ttl: 10\n  ratelimit: 0\n  ratelimit_whitelist: []\n  refuse_any: true\n  bootstrap_dns:\n%s  all_servers: true\n  fastest_addr: false\n  edns_client_subnet: true\n  enable_dnssec: true\n  aaaa_disabled: false\n  allowed_clients: []\n  disallowed_clients: []\n  blocked_hosts: []\n  parental_block_host: family-block.dns.adguard.com\n  safebrowsing_block_host: standard-block.dns.adguard.com\n  cache_size: 0\n  cache_ttl_min: 0\n  cache_ttl_max: 0\n  upstream_dns:\n%s%s  filtering_enabled: true\n  filters_update_interval: 24\n  parental_enabled: false\n  safesearch_enabled: false\n  safebrowsing_enabled: false\n  safebrowsing_cache_size: 1048576\n  safesearch_cache_size: 1048576\n  parental_cache_size: 1048576\n  cache_time: 30\n  rewrites: \n%s  blocked_services: []\ntls:\n  enabled: false\n  server_name: \"\"\n  force_https: false\n  port_https: 443\n  port_dns_over_tls: 853\n  allow_unencrypted_doh: false\n  strict_sni_check: false\n  certificate_chain: \"\"\n  private_key: \"\"\n  certificate_path: \"\"\n  private_key_path: \"\"\nfilters: %swhitelist_filters: []\nuser_rules:\n%sdhcp:\n  enabled: false\n  interface_name: \"\"\n  gateway_ip: \"\"\n  subnet_mask: \"\"\n  range_start: \"\"\n  range_end: \"\"\n  lease_duration: 86400\n  icmp_timeout_msec: 1000\nclients: []\nlog_file: \"\"\nverbose: false\nschema_version: 6\n", "  - 101.6.6.6:5353\n", "  - 101.6.6.6:5353\n", WhiteList, Rewrite, ADFilterRules, Hosts);
		fclose(yaml);
		system("cls");
		if (DNSServer == 1)printf("\n已选定：%s\n\n", "Cisco OpenDNS 加密版（中国香港）");
		else if (DNSServer == 2)printf("\n已选定：%s\n\n", "GoogleDNS（美国中部）");
		else if (DNSServer == 3)printf("\n已选定：%s\n\n", "AdGuardDNS（俄罗斯）");
		else if (DNSServer == 4)printf("\n已选定：%s\n\n", "IBM Quad9（美国中部）");
		else if (DNSServer == 5)printf("\n已选定：%s\n\n", "CloudflareDNS（中国香港）");
		else printf("\n已选定：%s\n\n", "清华大学TUNA666（教育网节点）");
		if (ADSwitch == 1)printf("%s\n\n","已开启Adblock Plus广告拦截功能");
		else if (ADSwitch == 2)printf("%s\n\n", "已开启AdGuard广告拦截功能");
		else printf("%s\n\n", "已关闭广告拦截功能");
		if (Geo_Mode == 2)printf("%s\n\n", "已启用全局模式");
		else printf("%s\n\n", "已开启DNS分流");
	return 0;
}

int NetFixTool() {
	Reset();
	printf("\nDNS解析服务器已成功恢复初始设置！\n\n");
	system("pause");
	return 0;
}

int Reset() {
	system("copy /y hosts.bak %windir%\\System32\\drivers\\etc\\hosts");
	system("del hosts.bak");
	system("taskkill /f /im AdGuardHome.exe");
	system("del AdGuardHome.yaml");
	system("rmdir /s/q data");
	system("rmdir /s/q agh-backup");
	system("netsh interface ip set dns \"以太网\" dhcp");
	system("netsh interface ipv6 set dns \"以太网\" dhcp");
	system("netsh interface ip set dns \"WLAN\" dhcp");
	system("netsh interface ipv6 set dns \"WLAN\" dhcp");
	system("ipconfig /flushdns");
	system("cls");
	printf("检测到计算机上存在的网络适配器：\n");
	printf("---------------------------------------------------\n");
	system("ipconfig /all >adapter.list &type adapter.list | find \"适配器\"");
	printf("---------------------------------------------------\n\n");
	printf("\n已自动恢复“以太网”“WLAN”适配器设置，如需恢复其它适配器，请手动恢复！\n\n");
	system("del adapter.list");
	return 0;
}

int RunLocalDNSServer() {
	printf("正在初始化. . .\n\n");
	system("copy /y hosts %windir%\\System32\\drivers\\etc\\hosts");
	system("copy /y %windir%\\System32\\drivers\\etc\\hosts hosts.bak");
	system("del %windir%\\System32\\drivers\\etc\\hosts");
	system("copy /y hosts %windir%\\System32\\drivers\\etc\\hosts");
	printf("\n正在准备配置文件. . .\n\n");
	system("copy /y index.yaml AdGuardHome.yaml");
	printf("\n正在部署DNS解析服务器. . .\n\n");
	system("start "" /min AdGuardHome.exe");
	printf("正在将DNS解析服务器设置为本地解析（可能会有报错，忽略即可）. . .\n\n");
	system("netsh interface ip set dns \"以太网\" static 127.0.0.1");
	system("netsh interface ipv6 set dns \"以太网\" static ::1");
	system("netsh interface ip set dns \"WLAN\" static 127.0.0.1");
	system("netsh interface ipv6 set dns \"WLAN\" static ::1");
	system("ipconfig /flushdns");
	system("cls");
	printf("准备验证DNS，请耐心等待5s，不要退出. . .\n\n");
	system("TIMEOUT /T 1 /NOBREAK");
	printf("\n正在进行DNS解析检测. . .\n\n");
	printf("正在检测国内网站. . .\n\n");
	printf("正在检测百度解析情况. . .\n\n");
	system("nslookup www.baidu.com 127.0.0.1");
	printf("正在检测腾讯解析情况. . .\n\n");
	system("nslookup www.qq.com 127.0.0.1");
	printf("正在检测英雄联盟解析情况. . .\n\n");
	system("nslookup lol.qq.com 127.0.0.1");
	printf("正在检测王者荣耀解析情况. . .\n\n");
	system("nslookup pvp.qq.com 127.0.0.1");
	printf("正在检测境外网站. . .\n\n");
	printf("正在检测谷歌解析情况. . .\n\n");
	system("nslookup www.google.com 127.0.0.1");
	printf("正在检测油管解析情况. . .\n\n");
	system("nslookup www.youtube.com 127.0.0.1");
	printf("正在检测脸书解析情况. . .\n\n");
	system("nslookup www.facebook.com 127.0.0.1");
	printf("正在检测推特解析情况. . .\n\n");
	system("nslookup twitter.com 127.0.0.1");
	printf("正在检测Twitch解析情况. . .\n\n");
	system("nslookup www.twitch.tv 127.0.0.1");
	printf("已完成所有DNS解析的检测！\n\n");
Menu2:system("cls");
	printf("-------------------------------------------------------------------------------------\n");
	printf("-----------------------------------DNS部署成功！-------------------------------------\n");
	printf("-------------------------------------------------------------------------------------\n");
	printf("注意：使用防污染DNS期间请不要关闭本窗口及其弹出窗口，后台最小化即可！！！\n");
	printf("如需停止DNS解析请不要直接关闭窗口，否则会导致无法上网！！！\n");
	printf("如果不小心关闭本软件，可以重新打开本软件恢复默认DNS！！！\n");
	printf("-------------------------------------------------------------------------------------\n\n");
	printf("检测到计算机上存在的网络适配器：\n");
	printf("---------------------------------------------------\n");
	system("ipconfig /all >adapter.list &type adapter.list | find \"适配器\"");
	printf("---------------------------------------------------\n\n");
	printf("本地DNS可通过以下ip地址远程共享：\n");
	printf("---------------------------------------------------\n");
	system("type adapter.list | find \"IPv4 地址\"");
	system("type adapter.list | find \"IPv6 地址\"");
	printf("---------------------------------------------------\n");
	printf("\n软件已默认配置了\"以太网\"\"WLAN\"适配器上的DNS，如需在其他适配器上配置本地DNS，请自行配置其为127.0.0.1与::1即可！\n");
	printf("如需关闭本地DNS并恢复默认DNS设置，请直接输入x并按回车：");
	scanf("%s",Adapter);
	if (Adapter[0] == 'x'|| Adapter[0] == 'X') {
		Reset();
		printf("\nDNS解析服务器已成功恢复初始设置！\n\n");
		return 0;
	}
	else {
		goto Menu2;
	}
	}
	

int ConfigEditor() {
	printf("请选择修改方式：\n\n1.图形界面（用户名与密码默认均为root）\n\n2.记事本\n\n请输入：");
	scanf("%d", &fixmode);
	if (fixmode == 2) {
		if ((yaml = fopen("index.yaml", "r")) == NULL) {
			Config_gen();
		}
		system("copy /y index.yaml index.yaml.bak");
		system("notepad.exe index.yaml");
		printf("\n请在弹出窗口中修改配置文件后，");
		system("pause");
	}
	else {
		printf("正在准备配置文件. . .\n\n");
		system("copy /y index.yaml index.yaml.bak");
		system("copy /y index.yaml AdGuardHome.yaml");
		printf("正在部署DNS解析服务器. . .\n\n");
		system("start "" /min AdGuardHome.exe");
		system("explorer.exe http://127.0.0.1");
		printf("\n请在弹出窗口中修改配置文件后，");
		system("pause");
		system("taskkill /f /im AdGuardHome.exe");
		system("copy /y AdGuardHome.yaml index.yaml");
		system("del AdGuardHome.yaml");
		system("rmdir /s/q data");
		system("rmdir /s/q agh-backup");
		system("cls");
	}
	return 0;
}

int ConfigToDefault() {
	if ((bak = fopen("index.yaml.bak", "r")) != NULL){
		printf("软件目录中找到上次的配置备份，请选择恢复模式：\n\n1.恢复到上一次的配置\n\n2.恢复初始状态\n\n请输入：");
		scanf("%d", &fixmode);
		if (fixmode == 1) {
			system("copy /y index.yaml.bak index.yaml");
			printf("\n已成功恢复到上一次的配置！\n");
			return 0;
		}
	}
	system("cls");
	Config_gen();
	printf("\n已成功恢复初始状态！\n");
	system("pause");
	return 0;
}

int NSTool() {
	Boot();
	printf("正在初始化. . .\n\n");
	printf("\n正在准备配置文件. . .\n\n");
	system("copy /y index.yaml AdGuardHome.yaml");
	printf("\n正在部署DNS解析服务器. . .\n\n");
	system("start "" /min AdGuardHome.exe");
	system("ipconfig /flushdns");
	NSMenu:system("cls");
	printf("请输入要查询的域名,返回上一级请输入@：\n");
	scanf("%s",domain );
	if (domain[0] == '@') {
		system("taskkill /f /im AdGuardHome.exe");
		system("del AdGuardHome.yaml");
		system("rmdir /s/q data");
		system("rmdir /s/q agh-backup");
		return 0;
	}
	else {
		sprintf(NSCommand, "nslookup %s 127.0.0.1", domain);
		printf("\n以下为无污染DNS解析结果：\n\n");
		system(NSCommand);
		system("pause");
		goto NSMenu;
	}
	return 0;
}

int Help() {
	printf("正在打开在线帮助. . .\n");
	system("explorer https://hxhgts.github.io/AntiDNSPollute/");
	return 0;
}

int Boot() {
	mode = 0;
	system("taskkill /f /im AdGuardHome.exe");
	system("del AdGuardHome.yaml");
	system("rmdir /s/q data");
	system("rmdir /s/q agh-backup");
	system("cls");
	if ((fopen("hosts", "r")) == NULL) {
		SystemHosts = fopen("hosts", "w");
		fprintf(SystemHosts, "##可以在下面自由添加需要的hosts信息，仅会在模式1下生效!\n");
		fprintf(SystemHosts, "127.0.0.1 localhost\n");
		fclose(SystemHosts);
	}
	if ((AdGuardHome = fopen("AdGuardHome.exe", "r")) == NULL) {
		return 1;
	}
	else {
		if ((yaml = fopen("index.yaml", "r")) == NULL) {
			Config_gen();
			printf("模式2配置文件已生成！\n\n");
			system("pause");
		}
		return 0;
	}
}

int FixHosts() {
	printf("正在恢复默认Hosts文件. . .\n\n");
	SystemHosts = fopen("hosts", "w");
	fprintf(SystemHosts, "127.0.0.1 localhost\n");
	fclose(SystemHosts);
	system("del %windir%\\System32\\drivers\\etc\\hosts");
	system("copy /y hosts %windir%\\System32\\drivers\\etc\\hosts");
	system("del hosts");
	system("ipconfig /flushdns");
	printf("\n已成功恢复默认Hosts文件！\n\n");
	system("pause");
	system("cls");
	return 0;
}
