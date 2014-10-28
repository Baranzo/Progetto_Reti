/*
 * myTest_list.c
 * 
 * Copyright 2014 thegamer <thegamer@littlewhite> baranzo <baranzo@Yuna>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include "myTest.h"

//dummy del piffero, intanto provo ste benedette funzioni
sys_info* fill_dummy(sys_info *pt)
{
	interface *intf;
	ipAddr *ip;
	
	
	pt=(sys_info*)malloc(sizeof(sys_info));
	intf=(interface*)malloc(sizeof(interface));
	ip=(ipAddr*)malloc(sizeof(ipAddr));
	
	strcpy(pt->hostname,"BaranzoDummy");
	strcpy(pt->os_name,"Baranzian");
	strcpy(pt->os_version,"0.0.0");
	strcpy(pt->manufacturer,"BaranzoCorp.");
	pt->memory=65536;
	
	
	strcpy(intf->type,"optical");
	strcpy(intf->ker_name,"opt0");
	strcpy(intf->mac_addr,"ab:cd:ef:00:11:22");
	strcpy(intf->dev, "optif0");
	
	strcpy(ip->addr,"192.168.0.1");
	strcpy(ip->scope,"link");
	strcpy(ip->version,"IPv4");
	
	pt->interfaces=intf;
	intf->ip=ip;
	
	return pt;
	
}
