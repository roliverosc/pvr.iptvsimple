/*
 *  Copyright (C) 2005-2020 Team Kodi
 *  https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSE.md for more information.
 */

#pragma once

#include "Channels.h"
#include "ChannelGroups.h"

#include <string>

#include <kodi/libXBMC_pvr.h>

namespace iptvsimple
{
  static const std::string M3U_START_MARKER        = "#EXTM3U";
  static const std::string M3U_INFO_MARKER         = "#EXTINF";
  static const std::string M3U_GROUP_MARKER        = "#EXTGRP:";
  static const std::string TVG_URL_MARKER          = "x-tvg-url=";
  static const std::string TVG_INFO_ID_MARKER      = "tvg-id=";
  static const std::string TVG_INFO_ID_MARKER_UC   = "tvg-ID="; //some provider incorrectly use an uppercase ID
  static const std::string TVG_INFO_NAME_MARKER    = "tvg-name=";
  static const std::string TVG_INFO_LOGO_MARKER    = "tvg-logo=";
  static const std::string TVG_INFO_SHIFT_MARKER   = "tvg-shift=";
  static const std::string TVG_INFO_CHNO_MARKER    = "tvg-chno=";
  static const std::string GROUP_NAME_MARKER       = "group-title=";
  static const std::string CATCHUP                 = "catchup=";
  static const std::string CATCHUP_DAYS            = "catchup-days=";
  static const std::string CATCHUP_SOURCE          = "catchup-source=";
  static const std::string CATCHUP_SIPTV           = "timeshift=";
  static const std::string CATCHUP_CORRECTION      = "catchup-correction=";
  static const std::string KODIPROP_MARKER         = "#KODIPROP:";
  static const std::string EXTVLCOPT_MARKER        = "#EXTVLCOPT:";
  static const std::string EXTVLCOPT_DASH_MARKER   = "#EXTVLCOPT--";
  static const std::string RADIO_MARKER            = "radio=";
  static const std::string PLAYLIST_TYPE_MARKER    = "#EXT-X-PLAYLIST-TYPE:";

  class PlaylistLoader
  {
  public:
    PlaylistLoader(iptvsimple::Channels& channels, iptvsimple::ChannelGroups& channelGroups);

    bool LoadPlayList();
    void ReloadPlayList();

  private:
    static std::string ReadMarkerValue(const std::string& line, const std::string& markerName);
    static void ParseSinglePropertyIntoChannel(const std::string& line, iptvsimple::data::Channel& channel, const std::string& markerName);

    std::string ParseIntoChannel(const std::string& line, iptvsimple::data::Channel& channel, std::vector<int>& groupIdList, int epgTimeShift, int catchupCorrectionSecs);
    void ParseAndAddChannelGroups(const std::string& groupNamesListString, std::vector<int>& groupIdList, bool isRadio);

    std::string m_m3uLocation;
    std::string m_logoLocation;

    iptvsimple::ChannelGroups& m_channelGroups;
    iptvsimple::Channels& m_channels;
  };
} //namespace iptvsimple